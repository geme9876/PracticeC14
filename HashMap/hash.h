#pragma once
#include <string>
#include <vector>
#include <list>

namespace JHash {
	template <typename T>
	class hash
	{
	public:
		size_t operator()(const T& key)const;
		//key를 byte로 보고 정수형으로 누적시켜 해쉬값을 만든다
	};



	//특정 개체에 대해선 다른 멤버변수까지 키로 사용할 수가 있기때문에 특수화를 통해 개별적으로 구현한다
	template <>
	class hash<std::string>
	{
	public:
		size_t operator()(const std::string& key) const;
	};



	size_t hash<std::string>::operator()(const std::string& key) const
	{
		size_t sum = 0;
		for (size_t i = 0; i < key.size(); i++)
		{
			sum += (unsigned char)key[i];
		}
		return sum;
	}
	template<typename HashMap>
	class const_hash_map_iterator :
		public std::iterator<std::bidirectional_iterator_tag, typename HashMap::value_type> // iterator<반복자 타입,항목(저장 데이터) 타입>
		//hashmap은 비선형 자료구조로서 양방향 컨테이너(++,--,== 등)를 지원해야한다
	{
		friend HashMap;
	public:

		using value_type = typename HashMap::value_type;
		using list_iterator_type = typename HashMap::ListType::const_iterator;

		//양방향 반복자는 반드시 디폴트 생성자를 제공해야한다
		const_hash_map_iterator();
		const_hash_map_iterator(size_t bucket, list_iterator_type listIt, const HashMap* inHashmap);
		const value_type& operator*() const;


		//리턴 타입은 반드시 -> 연산자 적용이 되어있어야함
		//컴파일러가 ->로 찾을 수 있는 pair<const Key,T>에 대한 포인터를 리턴한다
		const value_type* operator->() const;
		//전위연산 ++a
		const_hash_map_iterator<HashMap>&  operator++();
		//후위연산 a++
		const_hash_map_iterator<HashMap> operator++(int);

		const_hash_map_iterator<HashMap>&  operator--();
		const_hash_map_iterator<HashMap> operator--(int);


		bool operator==(const const_hash_map_iterator<HashMap>& rhs) const;
		bool operator!=(const const_hash_map_iterator<HashMap>& rhs) const;
	protected:
		size_t mBucketIndex;
		list_iterator_type mListIterator;
		const HashMap* mHashmap;

		//operator ++ -- 에서 사용할 편의함수
		void increment();
		void decrement();
	};


	template <typename HashMap>
	class hash_map_iterator : public const_hash_map_iterator<HashMap>
	{
		friend HashMap;
	public:


		using value_type = typename const_hash_map_iterator<HashMap>::value_type;
		using list_iterator_type = typename HashMap::ListType::iterator;

		hash_map_iterator();
		hash_map_iterator(size_t bucket, list_iterator_type listIt, HashMap* isHashmap);
		value_type& operator*();

		value_type* operator->();

		hash_map_iterator<HashMap>& operator++();
		hash_map_iterator<HashMap> operator++(int);

		hash_map_iterator<HashMap>& operator--();
		hash_map_iterator<HashMap> operator--(int);


	};


	template<typename Key, typename T, typename Compare = std::equal_to<Key>, typename Hash = hash<Key> >
	class hash_map
	{
	public:
		using key_type = Key;
		using mapped_type = T;

		// <> stl 퍼블릭 앨리어스  C++표준을 지키는 STL 컨테이너는 반드시 아래 앨리어스를 지원해야한다

		using value_type = std::pair<const Key, T>;
		using reference = std::pair<const Key, T>&;
		using const_reference = const std::pair<const Key, T>&;
		using size_type = size_t;
		using difference_type = ptrdiff_t;


		using hash_map_type = hash_map<Key, T, Compare, Hash>;

		using iterator = hash_map_iterator<hash_map_type>;
		using const_iterator = const_hash_map_iterator<hash_map_type>;

		friend class hash_map_iterator<hash_map_type>;
		friend class const_hash_map_iterator<hash_map_type>;


		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		const_iterator cbegin() const;
		const_iterator cend() const;

		// </>


		void insert(const value_type& k);
		void erase(const key_type& k);
		value_type* find(const key_type& k);
		const value_type* find(const key_type& k)const;

		T& operator[](const key_type& k);

		// 크기 관련 메서드
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		//편의 가변 메서드 (객체의 상태를 바꾸는 메서드)
		void swap(hash_map_type& hashIn);
		void CopyFrom(const hash_map<Key, T, Compare, Hash>&  src);


		explicit hash_map(const Compare& comp = Compare(), size_t numBuckets = 101, const Hash& hash = Hash());
		//복제 생성자
		hash_map(const hash_map<Key, T, Compare, Hash>& src);
		//이동생성자
		hash_map(hash_map<Key, T, Compare, Hash>&& src) noexcept;
		// stl 컨테이너의 조건으로 이동에 관련해서 noexcept가 있어야한다
		// vector는 연산과정에서 예외가 발생하면 예전의 상태로 되돌리는 강력한 에외 안전성 보장을 제공하는데
		//복사생성자는 원본 객체를 변경하지 않고 이동 시멘틱은 원본 객체를 파괴하기 때문에 이동에 관련한 모든 예외는 강력한 예외 안전성 보장을 위반한다
		//noexcept를 사용하지 않을 경우에 stl은 이동연산 대신 덜 효율적인 복사 연산을 사용한다

		//복제 대입 연산자
		hash_map<Key, T, Compare, Hash>& operator=(const hash_map<Key, T, Compare, Hash>& src);
		//이동 대입 연산자
		hash_map<Key, T, Compare, Hash>& operator=(hash_map<Key, T, Compare, Hash>&& src) noexcept;
		virtual ~hash_map();
	private:

		using ListType = std::list<value_type>; //버켓
		std::vector<ListType> mBuckets;

		//템플릿 파라미터에 의존적인 타입을 사용할때는 typename을 붙여줘야한다
		typename ListType::iterator findElem(const key_type& k, size_t& bucket);


		size_t mSize;
		Compare mComp;
		Hash mHash;
	};





}
#include "hash.inl"
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
		//key�� byte�� ���� ���������� �������� �ؽ����� �����
	};



	//Ư�� ��ü�� ���ؼ� �ٸ� ����������� Ű�� ����� ���� �ֱ⶧���� Ư��ȭ�� ���� ���������� �����Ѵ�
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
		public std::iterator<std::bidirectional_iterator_tag, typename HashMap::value_type> // iterator<�ݺ��� Ÿ��,�׸�(���� ������) Ÿ��>
		//hashmap�� ���� �ڷᱸ���μ� ����� �����̳�(++,--,== ��)�� �����ؾ��Ѵ�
	{
		friend HashMap;
	public:

		using value_type = typename HashMap::value_type;
		using list_iterator_type = typename HashMap::ListType::const_iterator;

		//����� �ݺ��ڴ� �ݵ�� ����Ʈ �����ڸ� �����ؾ��Ѵ�
		const_hash_map_iterator();
		const_hash_map_iterator(size_t bucket, list_iterator_type listIt, const HashMap* inHashmap);
		const value_type& operator*() const;


		//���� Ÿ���� �ݵ�� -> ������ ������ �Ǿ��־����
		//�����Ϸ��� ->�� ã�� �� �ִ� pair<const Key,T>�� ���� �����͸� �����Ѵ�
		const value_type* operator->() const;
		//�������� ++a
		const_hash_map_iterator<HashMap>&  operator++();
		//�������� a++
		const_hash_map_iterator<HashMap> operator++(int);

		const_hash_map_iterator<HashMap>&  operator--();
		const_hash_map_iterator<HashMap> operator--(int);


		bool operator==(const const_hash_map_iterator<HashMap>& rhs) const;
		bool operator!=(const const_hash_map_iterator<HashMap>& rhs) const;
	protected:
		size_t mBucketIndex;
		list_iterator_type mListIterator;
		const HashMap* mHashmap;

		//operator ++ -- ���� ����� �����Լ�
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

		// <> stl �ۺ� �ٸ��  C++ǥ���� ��Ű�� STL �����̳ʴ� �ݵ�� �Ʒ� �ٸ���� �����ؾ��Ѵ�

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

		// ũ�� ���� �޼���
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		//���� ���� �޼��� (��ü�� ���¸� �ٲٴ� �޼���)
		void swap(hash_map_type& hashIn);
		void CopyFrom(const hash_map<Key, T, Compare, Hash>&  src);


		explicit hash_map(const Compare& comp = Compare(), size_t numBuckets = 101, const Hash& hash = Hash());
		//���� ������
		hash_map(const hash_map<Key, T, Compare, Hash>& src);
		//�̵�������
		hash_map(hash_map<Key, T, Compare, Hash>&& src) noexcept;
		// stl �����̳��� �������� �̵��� �����ؼ� noexcept�� �־���Ѵ�
		// vector�� ����������� ���ܰ� �߻��ϸ� ������ ���·� �ǵ����� ������ ���� ������ ������ �����ϴµ�
		//��������ڴ� ���� ��ü�� �������� �ʰ� �̵� �ø�ƽ�� ���� ��ü�� �ı��ϱ� ������ �̵��� ������ ��� ���ܴ� ������ ���� ������ ������ �����Ѵ�
		//noexcept�� ������� ���� ��쿡 stl�� �̵����� ��� �� ȿ������ ���� ������ ����Ѵ�

		//���� ���� ������
		hash_map<Key, T, Compare, Hash>& operator=(const hash_map<Key, T, Compare, Hash>& src);
		//�̵� ���� ������
		hash_map<Key, T, Compare, Hash>& operator=(hash_map<Key, T, Compare, Hash>&& src) noexcept;
		virtual ~hash_map();
	private:

		using ListType = std::list<value_type>; //����
		std::vector<ListType> mBuckets;

		//���ø� �Ķ���Ϳ� �������� Ÿ���� ����Ҷ��� typename�� �ٿ�����Ѵ�
		typename ListType::iterator findElem(const key_type& k, size_t& bucket);


		size_t mSize;
		Compare mComp;
		Hash mHash;
	};





}
#include "hash.inl"
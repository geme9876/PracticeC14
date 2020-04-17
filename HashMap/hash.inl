

namespace JHash {
	template<typename T>
	size_t hash<T>::operator()(const T& key) const
	{
		size_t bytes = sizeof(key);
		size_t res = 0;
		for (size_t i = 0; i < bytes; ++i)
		{
			unsigned char b = *((unsigned char*)&key + i);
			res += b;
		}
		return res;
	}


	template<typename Key, typename T, typename Compare, typename Hash>
	inline hash_map<Key, T, Compare, Hash>::~hash_map()
	{
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	inline hash_map<Key, T, Compare, Hash>::hash_map(const Compare & comp, size_t numBuckets, const Hash & Hash)
	{
		//버켓은 최소한 하나 이상의 공간이 필요함
		if (numBuckets == 0)
		{
			throw std::invalid_argument("Number of buckets must be positive");
		}
		mBuckets.resize(numBuckets);
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	inline void hash_map<Key, T, Compare, Hash>::insert(const value_type & k)
	{

		size_t bucket;
		auto it = findElem(k.first, bucket);
		if (it != std::end(mBuckets[bucket]))
		{
			//항목이 이미 존재
			return;
		}
		else
		{
			mSize++;
			mBuckets[bucket].push_back(k);
		}
	}



	template<typename Key, typename T, typename Compare, typename Hash>
	inline void hash_map<Key, T, Compare, Hash>::erase(const key_type & k)
	{

		size_t bucket;
		auto it = findElem(k, bucket);
		if (it != std::end(mBuckets[bucket]))
		{
			mBuckets[bucket].erase(it);
			mSize--;
		}

	}



	template<typename Key, typename T, typename Compare, typename Hash>
	inline typename hash_map<Key, T, Compare, Hash>::value_type* hash_map<Key, T, Compare, Hash>::find(const key_type & k)
	{
		size_t bucket;
		auto it = findElem(k, bucket);
		if (it == std::end(mBuckets[bucket]))
		{
			return nullptr;
		}
		return &(*it);
	}



	template<typename Key, typename T, typename Compare, typename Hash>
	inline const typename hash_map<Key, T, Compare, Hash>::value_type* hash_map<Key, T, Compare, Hash>::find(const key_type & k) const
	{
		return const_cast<hash_map<Key, T, Compare, Hash>*>(this)->find(k);
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	inline T & hash_map<Key, T, Compare, Hash>::operator[](const key_type & k)
	{
		value_type* found = find(k);
		if (found == nullptr)
		{
			insert(std::make_pair(k, T()));
			found = find(k);
		}
		return found->second;
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	inline bool hash_map<Key, T, Compare, Hash>::empty() const
	{
		return mSize == 0;
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	inline typename hash_map<Key, T, Compare, Hash>::size_type hash_map<Key, T, Compare, Hash>::size() const
	{
		return mSize;
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	inline typename hash_map<Key, T, Compare, Hash>::size_type hash_map<Key, T, Compare, Hash>::max_size() const
	{
		return mBuckets[0].max_size();
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	inline void hash_map<Key, T, Compare, Hash>::swap(hash_map_type & hashIn)
	{
		std::swap(*this, hashIn);
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	inline typename hash_map<Key, T, Compare, Hash>::ListType::iterator
		hash_map<Key, T, Compare, Hash>::findElem(const key_type & k, size_t & bucket)
	{

		bucket = mHash(k) % mBuckets.size();
		for (auto it = std::begin(mBuckets[bucket]);
			it != std::end(mBuckets[bucket]);
			it++)
		{
			if (mComp(it->first, k))
			{
				return it;
			}
		}

		return std::end(mBuckets[bucket]);
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	inline void hash_map<Key, T, Compare, Hash>::CopyFrom(const hash_map<Key, T, Compare, Hash>& src)
	{
		mComp = src.mComp;
		mHash = src.mHash;
		mBuckets.resize(src.mBuckets.size());
		for (auto& bucket : src.mBuckets)
		{
			for (auto& elem : bucket)
			{
				insert(elem);
			}
		}
	}
	//복제생성자
	template<typename Key, typename T, typename Compare, typename Hash>
	inline hash_map<Key, T, Compare, Hash>::hash_map(const hash_map<Key, T, Compare, Hash>& src)
	{
		//깊은 복사를 수행한다
		CopyFrom(src);


	}
	//이동생성자
	template<typename Key, typename T, typename Compare, typename Hash>
	inline hash_map<Key, T, Compare, Hash>::hash_map(hash_map<Key, T, Compare, Hash>&& src) noexcept
	{
		mHash = std::move(src.mHash);
		mComp = std::move(src.mComp);
		mSize = std::move(src.mSize);
		mBuckets = std::move(src.mBuckets);
	}
	//복제 대입 연산자
	template<typename Key, typename T, typename Compare, typename Hash>
	inline typename hash_map<Key, T, Compare, Hash>& hash_map<Key, T, Compare, Hash>::operator=(const hash_map_type& src)
	{
		//자기 자신 대입 확인
		if (this == &src)
		{
			return *this;
		}
		// Clear current data.
		mBuckets.clear();
		mSize = 0;

		// Copy members.
		CopyFrom(src);

		return *this;


	}
	//이동 대입 연산자
	template<typename Key, typename T, typename Compare, typename Hash>
	inline typename hash_map<Key, T, Compare, Hash>& hash_map<Key, T, Compare, Hash>::operator=(hash_map_type&& src) noexcept
	{
		mHash = std::move(src.mHash);
		mComp = std::move(src.mComp);
		mSize = std::move(src.mSize);
		mBuckets = std::move(src.mBuckets);

		return *this;
	}



	template<typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::iterator
		hash_map<Key, T, Compare, Hash>::begin()
	{
		if (mSize == 0)
		{
			return end();
		}
		for (size_t i = 0; i < mBuckets.size(); ++i)
		{
			if (!mBuckets[i].empty())
			{
				return hash_map_iterator<hash_map_type>(i, std::begin(mBuckets[i]), this);
			}
		}
		//이곳까지 오는 상황은 있을수없다
		return end();
	}




	template<typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::iterator
		hash_map<Key, T, Compare, Hash>::end()
	{
		size_t bucket = mBuckets.size() - 1;
		return hash_map_iterator<hash_map_type>(bucket, std::end(mBuckets[bucket]), this);
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::const_iterator
		hash_map<Key, T, Compare, Hash>::begin() const
	{
		return const_cast<hash_map_type*>(this)->begin();
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::const_iterator
		hash_map<Key, T, Compare, Hash>::end() const
	{
		return const_cast<hash_map_type*>(this)->end();
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::const_iterator
		hash_map<Key, T, Compare, Hash>::cbegin() const
	{
		return begin();
	}

	template<typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::const_iterator
		hash_map<Key, T, Compare, Hash>::cend() const
	{
		return end();
	}


	/////////////////////////////////////////////	Const Itertator	/////////////////////////////////////////////




	template<typename HashMap>
	const_hash_map_iterator<HashMap>::const_hash_map_iterator() : mBucketIndex(0), mListIterator(list_iterator_type()), mHashmap(nullptr)
	{
		//디폴트 생성자
	}

	template<typename HashMap>
	const_hash_map_iterator<HashMap>::const_hash_map_iterator(size_t bucket, list_iterator_type listIt, const HashMap* isHashmap)
		:mBucketIndex(bucket), mListIterator(listIt), mHashmap(isHashmap)
	{
		//사용자 임의 생성자
	}

	template<typename HashMap>
	const typename const_hash_map_iterator<HashMap>::value_type& const_hash_map_iterator<HashMap>::operator*() const
	{
		//실제값을 리턴한다
		return *mListIterator;
	}


	template<typename HashMap>
	const typename const_hash_map_iterator<HashMap>::value_type* const_hash_map_iterator<HashMap>::operator->() const
	{
		//항목에 대한 포인터를 리턴한다
		return &(*mListIterator);
	}

	template<typename HashMap>
	const_hash_map_iterator<HashMap>& const_hash_map_iterator<HashMap>::operator++()
	{
		increment();
		return *this;
	}

	template<typename HashMap>
	const_hash_map_iterator<HashMap> const_hash_map_iterator<HashMap>::operator++(int)
	{
		auto oldIt = *this;
		increment();
		return oldIt;
	}


	template<typename HashMap>
	const_hash_map_iterator<HashMap>& const_hash_map_iterator<HashMap>::operator--()
	{
		decrement();
		return *this;
	}


	template<typename HashMap>
	const_hash_map_iterator<HashMap> const_hash_map_iterator<HashMap>::operator--(int)
	{
		auto oldIt = *this;
			decrement();
		return oldIt;
	}



	//inc dec 함수는 hashmap의 private 멤버에 접근하기 때문에  hash_map_iterator클래스를 hash_map의 friend로 선언해야한다
	template<typename HashMap>
	void const_hash_map_iterator<HashMap>::increment()
	{
		//현재 버킷에서 앞으로 이동한다
		++mListIterator;

		//현재 버킷의 반복자가 끝에 도달했다면
		//다음 버킷이 비어있는지 확인한 후 데이터가 있다면 이동한다
		auto& buckets = mHashmap->mBuckets;
		if (mListIterator == std::end(buckets[mBucketIndex]))
		{
			for (size_t i = mBucketIndex + 1; i < buckets.size(); i++)
			{
				if (!buckets[i].empty())
				{
					//데이터가 있는 버킷 발견
					//현재 반복자를 이 버킷의 시작 반복자로 셋팅
					mListIterator = std::begin(buckets[i]);
					mBucketIndex = i;
					return;
				}
			}
			//더 이상 데이터가없다 
			mBucketIndex = buckets.size() - 1;
			mListIterator = std::end(buckets[mBucketIndex]);
		}
	}

	template<typename HashMap>
	void const_hash_map_iterator<HashMap>::decrement()
	{

		auto& buckets = mHashmap->mBuckets;
		if (mListIterator == std::begin(buckets[mBucketIndex]))
		{
			//현재 반복자가 해당 버킷의 처음이라면  뒤쪽의 비지 않은 버킷을 찾는다
			for (int i = mBucketIndex - 1; i >= 0; --i)
			{
				if (!buckets[i].empty())
				{
					mListIterator = std::end(buckets[i]);
					--mListIterator;
					mBucketIndex = i;
					return;
				}
			}
			// 뒤에 데이터가 더이상 없다면 첫번째 버킷 list의 시작 반복자 위치의 직전( 끝 버킷의 끝 end of bucket )으로 셋팅한다
			// 이 end 버킷은 유효하지 않은 버킷이므로 아무 데이터도 가지고 있지 않는다
			mBucketIndex = buckets.size() - 1;
			mListIterator = std::end(buckets[mBucketIndex]);
		}
		else
		{
			//반복자가 시작 항목이 아니라면 거슬러 올라간다
			--mListIterator;
		}
	}


	template<typename HashMap>
	bool const_hash_map_iterator<HashMap>::operator==(const const_hash_map_iterator<HashMap>& rhs) const
	{
		//모든 필드가 동일해야한다
		return (mHashmap == rhs.mHashmap && mBucketIndex == rhs.mBucketIndex && mListIterator == rhs.mListIterator);;
	}
	template<typename HashMap>
	bool const_hash_map_iterator<HashMap>::operator!=(const const_hash_map_iterator<HashMap>& rhs) const
	{
		return !(*this == rhs); // == 반복자가 정의되어있으므로 이를 재활용한다
	}




	/////////////////////////////////////////////	Non-Const Itertator	/////////////////////////////////////////////




	template<typename HashMap>
	hash_map_iterator<HashMap>::hash_map_iterator() : const_hash_map_iterator<HashMap>()
	{

	}

	template<typename HashMap>
	hash_map_iterator<HashMap>::hash_map_iterator(size_t bucket, list_iterator_type listIt, HashMap* isHashmap)
		:const_hash_map_iterator<HashMap>(bucket, listIt, isHashmap)
	{

	}

	template<typename HashMap>
	typename hash_map_iterator<HashMap>::value_type& hash_map_iterator<HashMap>::operator*()
	{
		return const_cast<value_type&>(*this->mListIterator);
	}
	template<typename HashMap>
	typename hash_map_iterator<HashMap>::value_type* hash_map_iterator<HashMap>::operator->()
	{
		return const_cast<value_type*>(&(*this->mListIterator));
	}
	template<typename HashMap>
	hash_map_iterator<HashMap>& hash_map_iterator<HashMap>::operator++()
	{
		this->increment();
		return *this;
	}

	template<typename HashMap>
	hash_map_iterator<HashMap> hash_map_iterator<HashMap>::operator++(int)
	{
		auto oldIt = *this;
		this->increment();
		return oldIt;
	}


	template<typename HashMap>
	hash_map_iterator<HashMap>& hash_map_iterator<HashMap>::operator--()
	{
		this->decrement();
		return *this;
	}

	template<typename HashMap>
	hash_map_iterator<HashMap> hash_map_iterator<HashMap>::operator--(int)
	{
		auto oldIt = *this;
		this->decrement();
		return oldIt;
	}


}
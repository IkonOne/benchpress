#include <algorithm>
#include <vector>
#include <utility>

namespace bplib {

template<typename TKey, typename TValue>
class dense_map {
private:
    using pair_type = std::pair<TKey, TValue>;
    using vec_type = std::vector<pair_type>;

    vec_type _vec;
    bool _dirty = true;

    constexpr void dirty_check() {
        if (!_dirty)
            return;
        
        _dirty = false;
        std::sort(_vec.begin(), _vec.end());
    }

public:
    using size_type = typename vec_type::size_type;

    class iterator {
        friend class dense_map<TKey, TValue>;
    private:
        typename vec_type::iterator _it;

    public:
        using value_type = TValue;
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using pointer = TValue*;
        using reference = TValue&;


        constexpr iterator() = delete;
        ~iterator() = default;
        constexpr iterator(const iterator&) = default;

        constexpr iterator(typename vec_type::iterator it)
            : _it(it) {}

        constexpr iterator& operator++() {
            ++_it;
            return *this;
        }

        constexpr iterator& operator++(int) {
            iterator old = *this;
            operator++();
            return old;
        }

        constexpr iterator& operator--() {
            --_it;
            return *this;
        }

        constexpr iterator& operator--(int) {
            iterator old = *this;
            operator--();
            return old;
        }

        constexpr reference operator*() {
            return std::get<1>(*_it);
        }
    };

    friend constexpr bool operator<(const iterator& lhs, const iterator& rhs) {
        return std::get<0>(lhs) < std::get<0>(rhs);
    }

    dense_map() = default;
    ~dense_map() = default;
    dense_map(const dense_map&) = default;
    dense_map(std::initializer_list<typename vec_type::value_type> l)
        : _vec(l)
    {
        dirty_check();
    }

    constexpr iterator begin() noexcept {
        dirty_check();
        return _vec.begin();
    }

    constexpr iterator end() noexcept {
        dirty_check();
        return _vec.end();
    }

    void reserve(size_t size) { _vec.reserve(size); }
    constexpr size_type size() const { return _vec.size(); }
    const pair_type* data() const { return _vec.data(); }

    constexpr bool exists(const TKey& key) {
        dirty_check();
        return std::binary_search(
            _vec.begin, _vec.end(), key,
            [](const auto& it, const auto& key) {
                return std::get<0>(it) < key;
            });
    }

    constexpr iterator find(const TKey& key) {
        dirty_check();

        auto result = std::lower_bound(
            _vec.begin(), _vec.end(), key,
            [](const auto& it, const auto& key) {
                return std::get<0>(it) < key;
            });
        
        return iterator(result);
    }

    constexpr void push_back(const std::pair<TKey, TValue>& pair) {
        _dirty = true;
        _vec.push_back(pair);
    }
};

} // namespace bplib::ds
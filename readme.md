# Kth largest element

## Approach
- parition concept (like quick sort)
- until the pivot position comes out to be k-1, keep paritioning the array

- another way is using priority queue (min heap)
    - push elements to pq 
    - pop first k-1 elements 
    - pq.top is the answer

## Code
```c++
class Solution {
    void swap(int& a, int& b) {
        int c = a;
        a = b;
        b = c;
    }

    int partition(vector<int>& nums, int s, int e) {
        int i = s + 1, j = e, pivot = nums[s];

        while (i <= j) {
            while (i <= e && nums[i] >= pivot) i++;
            
            while (j > s && nums[j] < pivot) j--;
            
            if (i < j) swap(nums[i], nums[j]);
        }

        swap(nums[s], nums[j]);
        return j;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int s = 0, e = nums.size() - 1;
        k = k - 1;

        int j = partition(nums, s, e);

        while (j != k) {
            if (j < k) {
                s = j + 1;
            } else {
                e = j - 1;
            }
            j = partition(nums, s, e);
        }

        return nums[j];
    }
};
```

## Complexity
- Time: O(n) on average, O(n^2) in worst case
- Space: O(1)

---

# Top k frequent elements 

## Approach
- use hash map to count frequency of each element
- use priority queue (min heap) to keep track of top k elements
- push elements to pq 
- if pq size exceeds k, pop the top element (if using min heap)

```c++
struct Comparator {
    bool operator()(pair<int, int> x, pair<int, int> y) {
        return x.second > y.second;  // min heap (>) or max heap (<)
    }
};

class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int x:nums) {
            mp[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> pq;

        for(pair<int, int> x: mp) {
            pq.push(x);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()) {
            pair<int, int> x = pq.top();
            pq.pop();
            ans.push_back(x.first);
        }

        return ans;
    }
};
```

## Complexity
- Time: O(n log k) where n is the number of elements in the input array 
- Space: O(n) for the hash map and O(k) for the priority queue

# 
## Sorting is used in containers that allow random access

- Random access means we can access any element in constant time. Eg: Array, Vector and deque

## Sort array in c++

- Sorting function for array in c++ takes two address eg: (arr, arr + n)<br>
  (arr) is first address and (arr + n) is address 1 after the last element. (we dont use n - 1)<br>
- sort(arr, arr + n, greater < int >) sort in decreasing order.

## Sort vector in c++

```
// sort vector in increasing order
sort(vector.begin(), vector.end())

// sort vector in decreasing order
sort(vector.begin(), vector.end(), greater< int >)

// sort vector of pair by increasing order of their frequency using lambda fn
sort(begin(vectPair), end(vectPair), [&](pair<int,int> a, pair<int,int> b)
  { return a.second != b.second ? a.second > b.second : a.first < b.first; });
```

## Custom sorting function

```
struct Point{
    int x, y;
};

bool customFunction(Point p1, Point P2){
    return (p1.x < p1.y);
}

int main(){
    int n = 3;
    Point arr[n] = {{3,10}, {2,8}, {5,4}};
    sort(arr, arr + n, customFunction);

    for(auto p: arr)
      cout<< p.x << " " << p.y << "\n"; // 2 8, 3 10, 5 4
}
```

## The sort function:

- By default sort function uses quick sort
- Sort function internally uses a hybrid of quick sort, heap sort and insertion sort
- If quick sort is doing unfair partitioning and about to take more than nlogn time it switches to heap sort
- And when the array size becomes really small it switches to insertion sort

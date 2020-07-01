//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

 
vector<int> topKFrequent(vector<int>& nums, int k) {

    //统计次数
    //map<int, int> m;
    unordered_map<int, int> m; //<值，次数>

    for (int i = 0; i < nums.size(); ++i)
    {
        ++m[nums.at(i)];
    }

    //放入优先队列  注意：> 为小堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, CmpByValue> heap;

    int count = 0;
    auto iter = m.begin();
    for (; iter != m.end(); ++iter)
    {
        if (count == k)
        {
            break;
        }

        heap.push(*iter);

        ++count;
    }

    //将大于堆顶的元素放入 并删除堆顶
    for (; iter != m.end(); ++iter)
    {
        if (iter->second > heap.top().second)
        {
            heap.pop();
            heap.push(*iter);
        }
    }

    vector<int> res(k);
    for (int i = 0; i < k; ++i)
    {
        res.at(i) = heap.top().first;
        heap.pop();
    }

    return res;
}

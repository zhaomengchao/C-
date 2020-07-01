//����һ���ǿյ��������飬�������г���Ƶ��ǰ k �ߵ�Ԫ�ء�

 
vector<int> topKFrequent(vector<int>& nums, int k) {

    //ͳ�ƴ���
    //map<int, int> m;
    unordered_map<int, int> m; //<ֵ������>

    for (int i = 0; i < nums.size(); ++i)
    {
        ++m[nums.at(i)];
    }

    //�������ȶ���  ע�⣺> ΪС��
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

    //�����ڶѶ���Ԫ�ط��� ��ɾ���Ѷ�
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

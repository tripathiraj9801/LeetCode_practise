// Problem Link https://leetcode.com/problems/flatten-nested-list-iterator/description/

class NestedIterator
{
public:
    vector<int> data;
    int curr = 0, size;

    void DFS(vector<NestedInteger> &nestedList, vector<int> &data)
    {
        int i, n = nestedList.size();

        for (i = 0; i < n; i++)
        {
            if (nestedList[i].isInteger())
                this->data.push_back(nestedList[i].getInteger());
            else
                DFS(nestedList[i].getList(), this->data);
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        DFS(nestedList, this->data);
        this->size = this->data.size();
    }

    int next()
    {
        int ans = this->data[curr];
        curr += 1;
        return ans;
    }

    bool hasNext()
    {
        if (this->curr == this->size)
            return false;
        return true;
    }
};
// class NestedIterator
// {
// public:
//     stack<int> st;
//     NestedIterator(vector<NestedInteger> &nestedList)
//     {
//         ListToInteger(nestedList);
//         void ListToInteger(vector<NestedInteger> & nestedList)
//         {
//             for (int i = nestedList.size() - 1; i >= 0; i--)
//             {
//                 if (nestedList[i].isInteger())

//                     st.push(nestedList[i].getInteger());
//                 else
//                     ListToInteger(nestedList[i].getList());
//             }
//         }

//         int next()
//         {
//             int temp = st.top();
//             st.pop();
//             return temp;
//         }

//         bool hasNext()
//         {
//             return !st.empty();
//         }
//     };
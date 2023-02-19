// Problem Link
class NestedIterator
{
public:
    stack<int> st;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        ListToInteger(nestedList);
        void ListToInteger(vector<NestedInteger> & nestedList)
        {
            for (int i = nestedList.size() - 1; i >= 0; i--)
            {
                if (nestedList[i].isInteger())

                    st.push(nestedList[i].getInteger());
                else
                    ListToInteger(nestedList[i].getList());
            }
        }

        int next()
        {
            int temp = st.top();
            st.pop();
            return temp;
        }

        bool hasNext()
        {
            return !st.empty();
        }
    };
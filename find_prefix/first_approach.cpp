#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {

    vector<bool> survivals(phone_book.size(), true);
    vector<string> prefix_storage(phone_book.size());
    sort(phone_book.begin(), phone_book.end());
    for (int col = 0;; col++)
    {
        vector<bool> tmp_survivals(phone_book.size(), true);

        for (int row = 0; row < phone_book.size(); row++)
        {
            if (col != 0 && survivals[row] == true)
                continue;

            prefix_storage[row].push_back(phone_book[row][col]);

            for (int index = 0; index < row; index++)
            {
                if (prefix_storage[index] == prefix_storage[row])
                {
                    tmp_survivals[index] = false;
                    tmp_survivals[row] = false;

                    if (phone_book.at(index).size() - 1 == col)
                    {
                        printf("phone_book.at(index).size() : %d", phone_book.at(index).size());
                        printf("false\n");
                        return false;
                    }

                    if (phone_book.at(row).size() - 1 == col)
                    {
                        printf("false\n");
                        return false;
                    }
                    break;
                }
            }


        }
        survivals = tmp_survivals;
        bool flag = false;
        for (auto survival : survivals)
        {
            if (survival == false)
            {
                printf("there's possibility to be survival, %d\n",col);
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            printf("all is the true\n");
            return true;
        }
    }
    printf("true\n");
    return true;
}

int main()
{
    vector<string> phone_book = { "123", "456", "789" };
    for (auto k : phone_book)
        printf("%s\n",k.c_str());
    solution(phone_book);
    return 0;
}
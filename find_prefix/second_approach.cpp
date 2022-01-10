#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    vector<int> number_lengths(phone_book.size());

    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 0; j < phone_book.size(); j++)
        {
            if (i == j)
                continue;
            if (phone_book[j].find(phone_book[i].c_str()) == 0)
            {
                answer = false;
                return answer;
            }
        }
    }


    return answer;
}


int main()
{
    vector<string> phone_book = { "119", "97674223", "1195524421" };

    printf("%s", solution(phone_book) ? "true" : "false");
    return 0;
}
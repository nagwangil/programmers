#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> temp_numbers;

    for (auto num : numbers)
    {
        temp_numbers.push_back(to_string(num));
    }
    sort(temp_numbers.begin(), temp_numbers.end());

    for (auto num : temp_numbers)
    {
        printf("%s ", num.c_str());
    }
    printf("\n");

    for (int i = temp_numbers.size() - 1; i >= 0;)
    {
        int count = 0;
        while (true)
        {
            if (i - count == 0)
                break;

            if (temp_numbers.at(i - count).back() == '0')
            {
                string temp_number(temp_numbers.at(i - count));
                temp_number.pop_back();
                if (temp_numbers.at(i - count - 1) == temp_number)
                {
                    count++;
                }
                else
                    break;
            }
            else
            {
                printf("break  ");
                break;
            }
        }

        printf("push %s \n", temp_numbers[i - count].c_str());
        answer += temp_numbers[i - count];
        temp_numbers.erase(temp_numbers.begin() + i - count);

        i--;
    }

    return answer;
}

int main()
{
    vector<int> numbers = {0, 3, 30, 34, 5, 50, 500, 9};
    vector<int> numbers1 = {0, 6, 10, 2134, 213};
    printf("%s\n", solution(numbers1).c_str());

    return 0;
}
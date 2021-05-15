#include <iostream>
#include <vector>
#include <string>

using namespace std;


void solve(string s)
{
    string ret;
    int kurung_buka=0;
    int kurung_tutup=0;
    unsigned int i =0;

    kurung_buka = s[0] - '0';
    if (kurung_buka > 0)
    {
        for (int p = 0 ; p < kurung_buka ; p++)
        {
            ret += '(';
        }
    }
    ret += s[i];
    kurung_tutup = kurung_buka;


    while (1)
    {

        while(s[i] == s[i+1])
        {
            ret += s[i];
            i++;
        }

        if (i >= s.length()-1)
        {
           while (kurung_tutup > 0)
           {
               ret += ')';
               kurung_tutup--;
           }

           break;
        }
        //skip if repeat



        if (s[i] > s[i+1])
        {
            int c = s[i] - s[i+1];
            for (int p = 0 ; p < c ; p++)
            {
                ret += ')';
                kurung_tutup--;
                kurung_buka--;
            }
            ret += s[i+1];
        }

        if (s[i] < s[i+1])
        {
            int c = s[i+1] - s[i];
            for (int p = 0 ; p < c ; p++)
            {
                ret += '(';
                kurung_tutup++;
                kurung_buka++;
            }
            ret+= s[i+1];
        }

        i++;

    }

    cout << ret << endl;
    ret.clear();

}

int main()
{
    int test_case=0;
    cin >> test_case;

    string test_data;

    vector<string> ProblemCollection;
    for (int i = 0 ; i < test_case ; i++)
    {
        cin >> test_data;

        ProblemCollection.push_back(test_data);
        test_data.clear();
    }

    int problem_index =1;
    for (string s : ProblemCollection)
    {

        cout << "Case #" << problem_index << ": " ;
        solve(s);
        problem_index++;
    }
    return 0;
}

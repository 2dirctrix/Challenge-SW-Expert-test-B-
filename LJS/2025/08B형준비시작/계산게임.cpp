#include <deque>
using namespace std;
#define MAX_CARD 50000
int card[MAX_CARD * 2 + 5];
deque<int> ans_card[20][20];
int joker;
int ST, END;

void update(int indx, int dir) {
    int sum = 0;
    int Jcnt = 0;
    for (int i = 0; i < 4; i++) {
        if (card[indx + i] == -1)
            Jcnt++;
        else
            sum += card[indx + i];
    }

    for (int i = 0; i < 20; i++) {
        int num = (sum + (Jcnt * i)) % 20;
        if (dir == 0)
            ans_card[i][num].push_front(indx);
        else
            ans_card[i][num].push_back(indx);
    }

}

void init(int mJoker, int mNumbers[5])
{
    ST = END = MAX_CARD;
    joker = mJoker % 20;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            ans_card[i][j].clear();
        }
    }

    for (int i = 0; i < 5; i++) {
        card[MAX_CARD + i] = mNumbers[i];
    }
    //°è»ê

    for (int i = 0; i < 2; i++) {
        update(MAX_CARD + i, 1);
    }
    END += 5;
}

void putCards(int mDir, int mNumbers[5])
{
    if (mDir == 0) {
        ST -= 5;
        for (int i = 0; i < 5; i++) {
            card[ST + i] = mNumbers[i];
        }

        for (int i = 4; i >= 0; i--) {
            update(ST + i, mDir);
        }
    }
    else {
        for (int i = 0; i < 5; i++) {
            card[END + i] = mNumbers[i];
        }
        int tmp = END - 3;
        END += 5;
        for (int i = 0; i < 5; i++) {
            update(tmp + i, mDir);
        }
    }

}

int findNumber(int mNum, int mNth, int ret[4])
{

    auto& list = ans_card[joker][mNum];
    if (list.size() < mNth)
        return 0;
    else {
        int index = list[mNth - 1];
        for (int i = 0; i < 4; i++) {
            ret[i] = card[index + i];
        }
        return 1;
    }
}

void changeJoker(int mValue)
{
    joker = mValue % 20;
}
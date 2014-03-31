/*
ID:john1991
LANG: C++
PROG: beads
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int SearchForward(int cut, string bead);
int SearchBackward(int cut, string bead);

int main(){
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    int n;
    string beads;

    /* Read Inputs */
    string tmp;
    if(getline(fin, tmp)){
        n = atoi(tmp.c_str());
    }
    if(getline(fin, tmp)){
        beads = tmp;
    }

    int max = 0;
    for(int i = 0 ; i < n ; i++){
        int sum = SearchForward(i, beads) + SearchBackward(i, beads);
        if(sum >= n){
            sum = n;
            max = sum;
            i = n;
        }
        if(sum > max)
            max = sum;
    }

    fout<<max<<endl;
    fout.close();

    return 0;
}

int SearchForward(int cut, string bead){
    int count = 0;
    char b;
    if(cut == 0)
        b = bead[bead.length()-1];
    else
        b = bead[cut-1];
    // case b == 'w'
    if(b == 'w'){
        int p = cut;
        while(b == 'w'){
            if(p == 0)
                p = bead.length()-1;
            else
                p--;
            b = bead[p];

            if(p == cut)
                return bead.length();
        }
    }

    while(1){
        if(cut == 0)
            cut = bead.length()-1;
        else
            cut--;

        if(bead[cut] == b || bead[cut] == 'w')
            count++;
        else
            break;

        if(count >= bead.length())
            return bead.length();
    }

    return count;
}

int SearchBackward(int cut, string bead){
    int count = 0;
    char b;
    b = bead[cut];
    // case b == 'w'
    if(b == 'w'){
        int p = cut;
        while(b == 'w'){
            b = bead[p];
            if(p+1 == bead.length())
                p = 0;
            else
                p++;

            if(p == cut)
                return bead.length();
        }
    }

    while(1){
        if(bead[cut] == b || bead[cut] == 'w')
            count++;
        else
            break;

        if(cut+1 == bead.length())
            cut = 0;
        else
            cut++;

        if(count >= bead.length())
            return bead.length();
    }

    return count;
}


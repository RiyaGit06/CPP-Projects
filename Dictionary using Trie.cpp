#include<iostream>
#include<cstring>
#include<cctype>
#include <algorithm>
using namespace std;
class Node
{
public:
    bool end;
    string meaning;
    string type;
    string french;
    string spanish;
    string example;
    string synonyms[2];
    string antonyms[2];
    Node* next[26];
    Node()
    {
        meaning="";
        end=false;
        for(int i=0;i<26;i++)
            next[i]=NULL;
    }
};
Node* trie;
class Trie
{
public:
    Trie()
    {
       trie = new Node();
    }
    void Insert(string word, string m, string t, string f, string s, string e, string syn[2], string anto[2])
    {
        int i=0;
        Node* it = trie;
        while(i<word.size())
        {
            if(it->next[word[i]-'a'] == NULL)
                it->next[word[i]-'a'] = new Node;
            it = it->next[word[i]-'a'];
            i++;
        }
        it->end = true;
        it->meaning=m;
        it->type=t;
        it->french=f;
        it->spanish=s;
        it->example=e;
        int j=0;
        while(j<2){
          it->synonyms[j]=syn[j];
          j++;
        }
        j=0;
        while(j<2){
          it->antonyms[j]=anto[j];
          j++;
        }

    }
    void Search(string word)
    {
        int i=0,flag=0;
        Node* it = trie;
        while(i<word.size())
        {
            if(it->next[word[i]-'a'] == NULL){
                flag=1;
                break;
            }
            it = it->next[word[i]-'a'];
            i++;
        }
        if(it->end == false || flag==1 ){
                cout<<"\n Word does not Exist!";
            }
        else if(it->end)
        {
           cout<<"\n Meaning: "<<it->meaning;
           cout<<"\n Part of Speech: "<<it->type;
           cout<<"\n For example: "<<it->example;
           cout<<"\n Synonyms: "<<it->synonyms[0]<<", "<<it->synonyms[1];
           cout<<"\n Antonyms: "<<it->antonyms[0]<<", "<<it->antonyms[1];
        }

    }
    void Translation(string word)
    {
        int i=0,flag=0;
        Node* it = trie;
        while(i<word.size())
        {
            if(it->next[word[i]-'a'] == NULL){
                flag=1;
                break;
            }
            it = it->next[word[i]-'a'];
            i++;
        }
        if(it->end == false || flag==1 ){
            cout<<"\n Translation does not Exist!";
        }
        else if(it->end)
        {
            cout<<"\n French: "<<it->french;
            cout<<"\n Spanish: "<<it->spanish;
        }
    }
    void Delete(string word)
    {
        int i=0,flag=0;
        Node* it = trie;
        while(i<word.size())
        {
            if(it->next[word[i]-'a'] == NULL){
                flag=1;
                break;
            }
            it = it->next[word[i]-'a'];
            i++;
        }
        if(it->end == false || flag==1 ){
                cout<<"\n Word does not Exist!";
            }
        else if(it->end)
        {
            it->end=false;
            cout<<"\n Word deleted successfully..";
        }

    }
};
int main()
{
    string str;
    int i=0;
    Trie* mytrie = new Trie();
    string syn[2] = {"chart","mapping"};
    string anto[2] = {"disorganize","disorder"};
    mytrie->Insert( "map", "a diagrammatic representation of an area", "noun", "carte", "mapa", "I can't find Chattisgarh on the map.",syn,anto);

    syn[0]="infinitesimal"; syn[1]="small"; anto[0]="whole"; anto[1]="huge";
    mytrie->Insert( "minute", "infinitely or immeasurably small", "noun", "minute", "minuto", "The minute stain on the document was not visible to the naked eye.",syn,anto);

     syn[0]="accordance";  syn[1]="conformity";  anto[0]="withhold";  anto[1]="disagree";
    mytrie->Insert( "accord", "concurrence of opinion", "verb", "le consentement", "acuerdo", "The committee worked in accord on the bill, and it eventually passed.",syn,anto);

     syn[0]="apparent";  syn[1]="obvious";  anto[0]="unnoticeable";  anto[1]="inconspicuous";
    mytrie->Insert( "evident", "clearly revealed to the mind or the senses or judgment", "adjective", "évidente", "evidente", "That confidence was certainly evident in the way Smith handled the winning play with 14 seconds left on the clock.",syn,anto);

     syn[0]="perform";  syn[1]="pattern";  anto[0]="inaction";  anto[1]="monism";
    mytrie->Insert( "practice", "a customary way of operation or behavior", "noun", "s'entraîner", "práctica", "He directed and acted in plays every season and became known for exploring Elizabethan theatre practices.",syn,anto);

     syn[0]="desire";  syn[1]="mean";  anto[0]="disbelieve";  anto[1]="disregard";
    mytrie->Insert( "intend", "have in mind as a purpose", "verb", "vouloir", "tener intención", "\"Lipstick, as a product intended for topical use with limited absorption, is ingested only in very small quantities\" the agency said on its website.",syn,anto);

     syn[0]="alarm";  syn[1]="consideration";  anto[0]="serenity";  anto[1]="indifference";
    mytrie->Insert( "concern", "something that interests you because it is important", "noun", "préoccuper", "la preocupación", "The scandal broke out in October after former chief executive Michael Woodford claimed he was fired for raising concerns about the company's accounting practices",syn,anto);

     syn[0]="perpetrate";  syn[1]="intrust";  anto[0]="miscommit";  anto[1]="misintrust";
    mytrie->Insert( "commit", "perform an act, usually with a negative connotation", "verb", "s'engager", "cometer", "In an unprecedented front page article in 2003 The Times reported that Mr. Blair, a young reporter on its staff, had committed journalistic fraud.",syn,anto);

     syn[0]="inspection";  syn[1]="analysis";  anto[0]="unawareness";  anto[1]="glance";
    mytrie->Insert( "scrutiny", "heedful observation or examination", "noun", "examen minutieux", "escrutinio", "After the detailed scrutiny of the virus, scientists have reported to the government.",syn,anto);

     syn[0]="implicate";  syn[1]="necessitate";  anto[0]="exclude";  anto[1]="expel";
    mytrie->Insert( "entail", "to require or involve", "noun and verb", "entraîner", "implicar", "As the crowd increases in the parade, the security agencies entail more vigilant.",syn,anto);

     syn[0]="trouble";  syn[1]="hindrance";  anto[0]="pleasure";  anto[1]="assistance";
    mytrie->Insert( "nuisance", "Something or someone causes irritation.", "noun", "l' ennui", "molestia", "The minute stain on the document was not visible to the naked eye.",syn,anto);

     syn[0]="deadlock";  syn[1]="blockage";  anto[0]="movement";  anto[1]="advance";
    mytrie->Insert( "impasse", "A situation where no advancement is possible", "noun", "impasse", "punto muerto", "A successful person always tackles every impasse in his life.",syn,anto);

     syn[0]="excellent";  syn[1]="superlative";  anto[0]="mediocre";  anto[1]="ordinary";
    mytrie->Insert( "optimal", "Best or most favorable", "adjective", "optimale", "óptima", "I always believe in buying the optimal products.",syn,anto);

     syn[0]="rejuvenation";  syn[1]="restoration";  anto[0]="destruction";  anto[1]="deterioration";
    mytrie->Insert( "renaissance", "concurrence of opinion", "noun", "Renaissance", "Renacimiento", "The launching of JIO in India brought about a renaissance in uses of the Internet.",syn,anto);

     syn[0]="assault";  syn[1]="foray";  anto[0]="surrender";  anto[1]="protection";
    mytrie->Insert( "invasion", "An instance of capturing other’s territory by force", "noun", "l' incursion", "invasión", "India never believes in the invasion in other’s territory.",syn,anto);

     syn[0]="unnecessary";  syn[1]="needless";  anto[0]="vital";  anto[1]="necessary";
    mytrie->Insert( "redundant", "something that is not essential", "adjective", "redondante", "redundante", "We should use redundant money in the welfare of the needy people.",syn,anto);

     syn[0]="citation";  syn[1]="reference";  anto[0]="paraphrase";  anto[1]="reproach";
    mytrie->Insert( "quotation", "A repetition of words of the original author or speaker", "noun", "devis", "cotización", "His quotation was irrelevant in that context.",syn,anto);

     syn[0]="disavow";  syn[1]="forswear";  anto[0]="support";  anto[1]="acknowledge";
    mytrie->Insert( "renege", "denying to fulfill a promise", "noun and verb", "renier", "no cumplir", "The government has reneged to cut-down the price of the commodities.",syn,anto);

     syn[0]="affirm";  syn[1]="affirm";  anto[0]="reject";  anto[1]="refuse";
    mytrie->Insert( "assert", "Speaking or believing in a confident manner.", "verb", "affirmer", "afirmar", "He asserted that he would not come under any pressure.",syn,anto);

     syn[0]="dishonor";  syn[1]="disgrace";  anto[0]="honor";  anto[1]="repute";
    mytrie->Insert( "ignominy", "Public Shame", "noun", "ignominie", "ignominia", "The criminal faced ignominy after the verdict by the court.",syn,anto);

    int ch=1;
    char c;
    string w,m,t,f,s,e;


            cout<<"\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  "<<endl;
			cout<<"\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ "<<endl;
			cout<<"\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ "<<endl;
			cout<<"\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| "<<endl;
			cout<<"\n";
			do{
			cout<<"\n";
			cout<<"\n                                                   ====== Main Menu ======";
			cout<<"\n";
			cout<<"\n                                          1--> Insert a new word in dictionary";
			cout<<"\n                                          2--> Search for a word in dictionary";
			cout<<"\n                                          3--> Find Translation in French and Spanish";
			cout<<"\n                                          4--> Delete a word from dictionary";
			cout<<"\n                                          5--> Exit";
			cout<<"\n                                          Enter your choice: ";
			cin>>ch;


                switch(ch)
                {
                case 1:
                    {
                        cin.ignore();
                        cout<<"\n Enter the word: ";
                        getline(cin,w);
                        transform(w.begin(), w.end(), w.begin(), ::tolower);
                        cout<<"\n Enter its meaning: ";
                        getline(cin,m);
                        cout<<"\n Enter the part of speech to which it belongs: ";
                        getline(cin,t);
                        cout<<"\n Enter the french translation: ";
                        getline(cin,f);
                        cout<<"\n Enter the spanish translation: ";
                        getline(cin,s);
                        cout<<"\n Enter the example: ";
                        getline(cin,e);
                        cout<<"\n Enter synonym 1: ";
                        cin>>syn[0];
                        cout<<"\n Enter synonym 2: ";
                        cin>>syn[1];
                        cout<<"\n Enter antonym 1: ";
                        cin>>anto[0];
                        cout<<"\n Enter antonym 2: ";
                        cin>>anto[1];
                        mytrie->Insert(w, m, t, f, s, e,syn,anto);
                        break;
                    }
                case 2:
                    {
                        cin.ignore();
                        cout<<"\n Enter the word you want to search for: ";
                        getline(cin,w);
                        transform(w.begin(), w.end(), w.begin(), ::tolower);
                        mytrie->Search(w);
                        break;
                    }
                case 3:
                    {
                       cin.ignore();
                       cout<<"\n Enter the word you want translation for: ";
                       getline(cin,w);
                       transform(w.begin(), w.end(), w.begin(), ::tolower);
                       mytrie->Translation(w);
                       break;
                    }
                case 4:
                    {
                        cin.ignore();
                        cout<<"\n Enter the word you want to delete: ";
                        getline(cin,w);
                        transform(w.begin(), w.end(), w.begin(), ::tolower);
                        mytrie->Delete(w);
                        break;
                    }
                case 5:
                    exit(0);
                }
                cout<<"\n Do you want to continue(y/n): ";
                cin>>c;
            }
            while(c=='y' || c=='Y');
    }


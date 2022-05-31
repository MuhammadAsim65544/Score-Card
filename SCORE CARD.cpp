/*
Supervised By:
/////////////////////////////////////////////////
////////////Hon'able Sir MUHAMMAD NADEEM////////
///////////////////////////////////////////////
Submitted By:
MUHAMMAD ASIM | 3956-FBAS/BSCS/F-18(B)

Program:
A Cricket SCORECARD

 */

#include <iostream>
#include <iomanip>
#include<fstream>
//#include<curses.h>
//#include<conio.h>
#define MAX_PLAYERS 22
using namespace std;
// int erase(void);
class Player
{
protected:
    string p_name;

public:
    Player() {}
    void setter()
    {
        getline(cin, p_name);
    }

    /*
    virtual void generate_row() = 0;
    virtual void setter()
    {
        getline(cin, p_name);
    }
    virtual void set_id(int id) = 0;
    virtual int get_id() = 0;
    virtual void set_status(char st) = 0;
    virtual char get_status() = 0;
    virtual string get_name() = 0;
    virtual void incre_run() = 0;
    virtual void incre_ball() = 0;
    virtual void incre_six() = 0;
    virtual void incre_four() = 0;
    virtual int get_balls() = 0;
    virtual int get_run() = 0;
    virtual void add_into_runs(int) = 0;
    virtual void add_into_balls(int) = 0;
    virtual void decre_ball() = 0;
    virtual void export2file() = 0;*/
};
class Batsman : public Player
{
    int run, balls_played, no_of_4s, no_of_6s, ply_id;
    float strike_rate;
    char status; //if Out or Not

public:
    Batsman(int r = 0, int b = 0, int f = 0, int s = 0, double sr = 0.0)
        : Player(), run(r), balls_played(b), no_of_4s(f), no_of_6s(s), strike_rate(sr) {}
    void generate_row();
    void setter()
    {

        cout << "\nEnter Name of Batsman: ";
        Player::setter();
    }
    void set_id(int id) { ply_id = id; }
    int get_id() { return ply_id; }
    void set_status(char st) { status = st; }
    char get_status() { return status; }
    string get_name() { return p_name; }
    void incre_run() { run++; }
    void incre_ball() { balls_played++; }
    void incre_six()
    {
        no_of_6s++;
        balls_played++;
        run += 6;
    }
    void incre_four()
    {
        no_of_4s++;
        balls_played++;
        run += 4;
    }
    int get_run() { return run; }
    int get_balls() { return balls_played; }
    void add_into_runs(int value) { run += value; }
    void add_into_balls(int value) { balls_played += value; }
    void decre_ball() { balls_played--; }
    void export2file();
};
void Batsman :: export2file()
{
    fstream file;
    file.open("Scorecard.txt", ios::out | ios::app);
    if(file)
    {
        file << "\n| "<<ply_id<<" | " << p_name;
        for (int i = 0; i < (34 - p_name.length()); i++)
            file << " ";

        if (balls_played != 0)
            strike_rate = static_cast<float>((run / balls_played) * 100);
        file << "|  ";

        file << setw(3) << setfill(' ') << run << "   |  " << setw(3) << setfill(' ') << balls_played << "  |  " << setw(3) << setfill(' ') << no_of_4s << "   |  "
            << setw(3) << setfill(' ') << no_of_6s << "   |  " << setw(5) << setfill(' ')
            << setiosflags(ios::showpoint) << setprecision(1) << setiosflags(ios::fixed) << strike_rate << "  |" << resetiosflags(ios::showpoint) << resetiosflags(ios::fixed);
    }
    else
    {
        cout<<"\nERROR While Opening FILE, Terminating!";
        return;
    }
}
void Batsman::generate_row()
{
    if(status == 'o')
    {
        cout <<"\033[1;31m"<< "\n| "<<ply_id<<" | " << p_name;
        for (int i = 0; i < (34 - p_name.length()); i++)
            cout << " ";

        if (balls_played != 0)
            strike_rate = static_cast<float>((run / balls_played) * 100);
        cout << "|  ";
    
        cout << setw(3) << setfill(' ') << run << "   |  " << setw(3) << setfill(' ') << balls_played << "  |  " << setw(3) << setfill(' ') << no_of_4s << "   |  "
         << setw(3) << setfill(' ') << no_of_6s << "   |  " << setw(5) << setfill(' ')
         << setiosflags(ios::showpoint) << setprecision(1) << setiosflags(ios::fixed) << strike_rate << "  |" << resetiosflags(ios::showpoint) << resetiosflags(ios::fixed)<<"\033[0m";        
    }
    else
    {
        cout << "\n| "<<ply_id<<" | " << p_name;
        for (int i = 0; i < (34 - p_name.length()); i++)
            cout << " ";

        if (balls_played != 0)
            strike_rate = static_cast<float>((run / balls_played) * 100);
        cout << "|  ";
        cout << setw(3) << setfill(' ') << run << "   |  " << setw(3) << setfill(' ') << balls_played << "  |  " << setw(3) << setfill(' ') << no_of_4s << "   |  "
         << setw(3) << setfill(' ') << no_of_6s << "   |  " << setw(5) << setfill(' ')
         << setiosflags(ios::showpoint) << setprecision(1) << setiosflags(ios::fixed) << strike_rate << "  |" << resetiosflags(ios::showpoint) << resetiosflags(ios::fixed);
    }
}
class BOWLER:public Player
{
	protected: 
		int t_over,wicket,count,ts_of_bow,ch,wicket_run;
		double economy;
		public:
		/* BOWLER(string nam,int t_ovr,int wick,int countt,int ts_b,int chh,int wic_r,double eco):Player(nam),t_over(t_ovr),wicket(wick),
		count(countt),ts_of_bow(ts_b),ch(chh),wicket_run(wic_r),economy(eco){ }*/
		void  setter()
		{
			cout<<"ENTER BOWLER NAME: ";
			getline(cin,p_name);
			process();
		}
		void bowler_menu()
		{
			cout<<"_-_-_-_-_-_-_MENU\n";
			cout<<"0.Miss Ball\n";
			cout<<"1.Single\n";	
			cout<<"2.double\n";
			cout<<"3.Triple\n";
			cout<<"4.Four\n";
			cout<<"5.Six\n";
			cout<<"6.Wide ball\n";
			cout<<"7.No ball\n";
			cout<<"8.Wicket\n";
		}	
		void process()
		{
			for(int i=0;i<6;i++)
			{
				cout<<"BALL "<<i+1<<endl;
				bowler_menu();
				cout<<"Enter your choice: ";
				cin>>ch;
				switch(ch)
				{
					case 0:
						count++;
						if(count==6)
						{
							count=0;
							t_over++;
						}
						system("cls");
						getter();
						break;
					case 1:
						ts_of_bow++;
						count++;
						if(count==6)
						{
							count=0;
							t_over++;
						}
						economy=(ts_of_bow/count);
						system("cls");
						getter();
						break;
					case 2:
						ts_of_bow=ts_of_bow+2;
						count++;
						if(count==6)
						{
							count=0;
							t_over++;
						}
						economy=(ts_of_bow/count);
						system("cls");
						getter();
						break;
					case 3:
						ts_of_bow=ts_of_bow+3;
						count++;
						if(count==6)
						{
							count=0;
							t_over++;
						}
						economy=(ts_of_bow/count);
						system("cls");
						getter();
						break;
					case 4:
						ts_of_bow=ts_of_bow+5;
						count++;
						if(count==6)
						{
							count=0;
							t_over++;
						}
						economy=(ts_of_bow/count);
						system("cls");
						getter();
						break;
					case 5:
						ts_of_bow=ts_of_bow+6;
						count++;
						if(count==6)
						{
							count=0;
							t_over++;
						}
						economy=(ts_of_bow/count);
						system("cls");
						getter();
						break;
					case 6:
						if(i==0)
						{
							i=i;
							economy=economy;
							ts_of_bow++;
							if(count==6)
							{
								count=0;
								t_over++;
							}
							system("cls");
							getter();
						}
						else
						{
							i--;
							ts_of_bow++;
							if(count==6)
							{
								count=0;
								t_over++;
							}
							economy=(ts_of_bow/count);
							system("cls");
							getter();
						}
						break;
					case 7:
						if(i==0)
						{
							i=i;
							economy=economy;
							ts_of_bow++;
							if(count==6)
							{
								count=0;
								t_over++;
							}
							system("cls");
							getter();
						}
						else
						{
							i--;
							ts_of_bow++;
							if(count==6)
							{
								count=0;
								t_over++;
							}
							economy=(ts_of_bow/count);
							system("cls");
							getter();
						}					
						break;
					case 8:
						wicket++;
						count++;
						cout<<"Enter Run: ";
						cin>>wicket_run;
						ts_of_bow+=wicket_run;
						economy=(ts_of_bow/count);
						system("cls");
						getter();
						break;
				}
			}
		}
		void getter()
		{
			cout<<"\n             BOWLING MENU\n\n";
			cout<<"  BOWLER"<<setfill(' ')<<setw(13)<<"OVERS"<<setfill(' ')<<setw(13)<<"RUNS"<<setfill(' ')<<setw(13)<<"WICKETS"<<setfill(' ')<<setw(13)<<"ECONOMY"<<endl;
			cout<<"  "<<p_name<<setfill(' ')<<setw(13)<<t_over<<"."<<count<<setfill(' ')<<setw(12)<<ts_of_bow<<setfill(' ')<<setw(13)<<wicket<<setfill(' ')<<setw(13)<<economy<<endl;
		}	
};

/* 
 class Bowler : public Player
 {
     float overs, econ_rate;
     int run_given, maiden_overs;
     char status; //if Overs Finished or not
 public:
     void generate_row();
     void setter()
     {
         cout << "\nEnter Name of Bowler: ";
         Player::setter();
     }
 };*/
 // PROTOTYPES
void generate_score(Batsman *pp[], int counterr, string t1, string t2, char ts);
void begin_match(string& t1, string& t2, char& ts);
void headerintofile(Batsman *pp[], int counterr, string t1, string t2, char ts);

// TESTER
int main()
{
    Batsman *p[MAX_PLAYERS];
    int counter = -1, on_strike, addR, addB;
    string team1_name, team2_name;
    bool my_cond = true, my_cond2 = true, strike_rotation = false;
    char ch, ch2, ch3, toss;
    int ch1;
    for(int i = 0; i < 2; i++)
    {
        if(counter != -1) //For Next Team
        {
            
            begin_match(team1_name, team2_name, toss);
            // cout << "\nEnter Any Key if Match Begins.....";
            //if(getch()) system("cls");
            cout << "\nEnter Names of Openers: ";
            cin.ignore(10, '\n');
            p[++counter] = new Batsman;
            p[counter]->set_id(counter + 1);
            p[counter]->set_status('n');
            p[counter]->setter();

            p[++counter] = new Batsman;
            p[counter]->set_id(counter + 1);
            p[counter]->set_status('n');
            p[counter]->setter();
        }

        do
        {
            // cout << "\033[1;36m"<<"bold red text"<<"\033[0m\n";
            cout << "\n..........MENU..........\n"
                << "\033[1;37m\n1. Match Begin."
                << "\n2. View Scorecard (If Previously Saved)."
                << "\n3. Export Scorecard."
                << "\n4. Terminate.\033[0m";
                cout <<"\033[5;32;40m";
                cout<< "\nEnter Your Choice: ";
                cout <<"\033[m";
            cin >> ch;
            system("clear");
            switch (ch)
            {
            case '1':
                my_cond2 = true; //to continue entering score
                if(counter == -1) //For first Time batting
                {
                    begin_match(team1_name, team2_name, toss);
                    // cout << "\nEnter Any Key if Match Begins.....";
                    //if(getch()) system("cls");
                    cout << "\nEnter Names of Openers: ";
                    cin.ignore(10, '\n');
                    p[++counter] = new Batsman;
                    p[counter]->set_id(counter + 1);
                    p[counter]->set_status('n');
                    p[counter]->setter();

                    p[++counter] = new Batsman;
                    p[counter]->set_id(counter + 1);
                    p[counter]->set_status('n');
                    p[counter]->setter();

                }
                else cout<<"\n!!!!!!BACK TO MATCH!!!!!!\n";
                generate_score(p, counter, team1_name, team2_name, toss);

                

                do
                {
                    for (int i = counter; i >= 0; i--)
                    {
                        if (p[i]->get_status() == 'n')
                        {
                            on_strike = p[i]->get_id() - 1;
                            cout << "\n"
                                <<"\033[1;31m"<< p[i]->get_name() << " is on STRIKE....\033[0m";
                            break;
                        }
                    }
                    strike_rotation = false;
                    do
                    {

                        my_cond = true;
                        if (strike_rotation)
                        {
                            for (int i = counter; i >= 0; i--)
                            {
                                if (p[i]->get_status() == 'n')
                                {
                                    if (i != on_strike)
                                    {
                                        on_strike = p[i]->get_id() - 1;
                                        cout << "\n"
                                            <<"\033[1;31m"<< p[i]->get_name() << " is on STRIKE....\033[0m";
                                        strike_rotation = false;
                                        break;
                                    }
                                }
                            }
                        }
                        else
                        {
                        }

                        cout << "\nENTER WHAT Happened (For OnStrike Batsman).";
                        cout << "\n..........MENU..........\n"
                            << "\n1. Ball Missed."
                            << "\n2. FOUR!"
                            << "\n3. SIX!"
                            << "\n4. Single."
                            << "\n5. Double."
                            << "\n6. Triple."
                            << "\n7. Wide Ball."
                            << "\n8. NOBall."
                            << "\n9. Dead Ball."
                            << "\n10. OUT."
                            << "\n11. Manually want to Do something."
                            << "\n12. Back To MAIN MENU.\n";
                        cout <<"\033[5;32;40m";
                        cout << "\nEnter Your Choice: ";
                        cout <<"\033[m";
                        cin >> ch1;
                        system("clear");
                        switch (ch1)
                        {
                        case 1:
                            p[on_strike]->incre_ball();
                            generate_score(p, counter, team1_name, team2_name, toss);
                            
                            break;
                        case 2:
                            p[on_strike]->incre_four();
                            generate_score(p, counter, team1_name, team2_name, toss);
                            break;
                        case 3:
                            p[on_strike]->incre_six();
                            generate_score(p, counter, team1_name, team2_name, toss);
                            break;
                        case 4:
                            strike_rotation = true;

                            p[on_strike]->incre_ball();
                            p[on_strike]->incre_run();
                            generate_score(p, counter, team1_name, team2_name, toss);
                            break;
                        case 5:
                            p[on_strike]->incre_ball();
                            p[on_strike]->incre_run();
                            p[on_strike]->incre_run();
                            generate_score(p, counter, team1_name, team2_name, toss);
                            break;
                        case 6:
                            strike_rotation = true;
                            p[on_strike]->incre_ball();
                            p[on_strike]->incre_run();
                            p[on_strike]->incre_run();
                            p[on_strike]->incre_run();
                            generate_score(p, counter, team1_name, team2_name, toss);
                            break;
                        case 7:
                            p[on_strike]->incre_run();
                            generate_score(p, counter, team1_name, team2_name, toss);
                            break;
                        case 8:
                            p[on_strike]->incre_run();
                            cout << "\nENTER WHAT Happened on NOBALL?";
                            cout << "\n..........MENU..........\n"
                                << "\n1. Ball Missed."
                                << "\n2. FOUR!"
                                << "\n3. SIX!"
                                << "\n4. Single."
                                << "\n5. Double."
                                << "\n6. Triple."
                                << "\n7. OUT!";
                            cin >> ch2;
                            switch (ch2)
                            {
                            case '1':
                                p[on_strike]->incre_run();
                                generate_score(p, counter, team1_name, team2_name, toss);
                                break;
                            case '2':
                                p[on_strike]->incre_four();
                                p[on_strike]->decre_ball();                        
                                generate_score(p, counter, team1_name, team2_name, toss);
                                break;
                            case '3':
                                p[on_strike]->incre_six();
                                p[on_strike]->decre_ball();
                                generate_score(p, counter, team1_name, team2_name, toss);
                                break;
                            case '4':
                                strike_rotation = true;
                                p[on_strike]->incre_run();
                                generate_score(p, counter, team1_name, team2_name, toss);
                                break;
                            case '5':
                                p[on_strike]->incre_run();
                                p[on_strike]->incre_run();
                                generate_score(p, counter, team1_name, team2_name, toss);
                                break;
                            case '6':
                                strike_rotation = true;
                                p[on_strike]->incre_run();
                                p[on_strike]->incre_run();
                                p[on_strike]->incre_run();
                                generate_score(p, counter, team1_name, team2_name, toss);
                                break;
                            case '7':
                                cout<<"\nNo Ball, Not OUT!";
                                generate_score(p, counter, team1_name, team2_name, toss);
                            default:
                                cout <<"\033[5;32;40m";
                                cout<<"\nWRONG CHOICE!\nTRY AGAIN!";
                                cout <<"\033[m";
                            }
                            break;
                        case 9:
                            generate_score(p, counter, team1_name, team2_name, toss);
                            break;
                        case 10:
                            p[on_strike]->set_status('o');
                            my_cond = false;
                            break;
                        case 11:
                            cout <<"\033[5;32;40m";
                            cout<< "\nEnter Your Choice: ";
                            cout <<"\033[m";
                            cout << "\n..........MENU..........\n"
                                << "\n1. ADD to Runs."
                                << "\n2. ADD to Balls.\n";
                            cin>>ch3;
                            switch(ch3)
                            {
                                case '1':
                                    cout<<"\nENTER How much Runs to ADD or SUBTRACT: ";
                                    cin>>addR;
                                    p[on_strike]->add_into_runs(addR);
                                    generate_score(p, counter, team1_name, team2_name, toss);
                                break;
                                case '2':
                                    cout<<"\nENTER How much Balls to ADD or SUBTRACT: ";
                                    cin>>addB;
                                    p[on_strike]->add_into_balls(addB);
                                    generate_score(p, counter, team1_name, team2_name, toss);
                                break;
                                default:
                                    cout <<"\033[5;32;40m";
                                    cout<<"\nWRONG CHOICE!\nTRY AGAIN!";
                                    cout <<"\033[m";
                            }
                        case 12:
                            my_cond = false;
                            my_cond2 = false;
                            break;
                        default:
                            cout <<"\033[5;32;40m";
                            cout<<"\nWRONG CHOICE!\nTRY AGAIN!";
                            cout <<"\033[m";
                        }

                    } while (my_cond);

                    if ((counter < 11) && (my_cond2)) //to avoid get into 'OUT' code while 'BACK'
                    {
                        p[++counter] = new Batsman;
                        p[counter]->set_id(counter + 1);
                        p[counter]->set_status('n');
                        cin.ignore(10, '\n');
                        p[counter]->setter();
                        generate_score(p, counter, team1_name, team2_name, toss);
                    }
                    else
                        cout << "\nYou're into Out Menu";

                } while (my_cond2); 
                break;
                // ViewSCORECARD
                case '2':
                    if(counter != -1) generate_score(p, counter, team1_name, team2_name, toss);
                    else cout<<"\nNo SCORECARD Found!\nSELECT Choice 1 First.";
                break;
                // FILING
                case '3':
                    if(counter != -1)
                    {
                        headerintofile(p, counter, team1_name, team2_name, toss);
                        for(int i = 0; i <= counter; i++) p[i]->export2file();
                        cout<<"\nYour RECORD Has Been SAVED to File Named 'Scorecard.txt'.\nCheck it Out in same Directory.";
                    }
                    else cout<<"\nSorry! No RECORD Found!\nFirst Create Some...";
                break;
                // TERMINATE
                case '4':
                    return 0;
                default:
                    cout <<"\033[5;32;40m";
                    cout<<"\nWRONG CHOICE!\nTRY AGAIN!";
                    cout <<"\033[m";
            }

        }while(counter < 10); //while not all out




        cout<<"\n\nINNINGS is OVER!\nNEXT TEAM'S Batting NOW!\nPREVIOUS TEAM's RECORD is SAVED in SAME DIRECTORY as TEXTFILE\n\n";
    }

    
    // MAIN ENDS
    return 0;
}
void generate_score(Batsman *pp[], int counterr, string t1, string t2, char ts)
{
    int tempC = 0, total_run = 0, no_of_outs = 0, total_balls = 0;
    int overs;
    //system("cls");
    for (int i = 0; i < counterr; i++)
    {
        total_run += pp[i]->get_run();
        total_balls += pp[i]->get_balls();
        if (pp[i]->get_status() == 'o')
            no_of_outs++;
    }
    

    overs = total_balls / 6;
    cout<<"\033[1;37m\n.............................||||SCORECARD||||.................................";
    cout<<"\n.............................."<<t1<<"..vs.."<<t2<<".....................................";
    cout<<"\n..............................BATTING: ";
    if(ts == t1[0]) cout<<t1;
    else cout<<t2;
    cout<<" ....................................";
    cout << "\n.............................." << total_run << "/" << no_of_outs << "......." << overs << "." << overs % 6 << "...................................";
    cout << "\n ____________________________________________________________________________________"
         << "\n| N |                NAME               |   R    |   B   |   4s   |   6s   |  S/R    |\033[0m";
    
    while (tempC <= counterr)
    {
        pp[tempC]->generate_row();
        tempC++;
    }
}
void begin_match(string& t1, string& t2, char& ts)
{
    bool myCond = true; 
    cin.ignore(10, '\n');
    cout << "\nEnter Name of Team1: ";
    getline(cin, t1);
    cout << "\nEnter Name of Team2: ";
    getline(cin, t2);
    // CAPITALIZATION
    for(int i = 0; i < t1.length(); i++) t1[i] = toupper(t1[i]);
    for(int i = 0; i < t2.length(); i++) t2[i] = toupper(t2[i]);
    do
    {
        cout << "\nWhich Team Won TOSS?\nEnter (" << t1[0] << ") for " << t1 << " WHERE (" << t2[0] << ") for " << t2 << ": ";
        cin>>ts;ts = toupper(ts);
        if((ts == t1[0]) || (ts == t2[0])) myCond = false;
    } while (myCond);
          
}
void headerintofile(Batsman *pp[], int counterr, string t1, string t2, char ts)
{
    int tempC = 0, total_run = 0, no_of_outs = 0, total_balls = 0;
    int overs;
    for (int i = 0; i < counterr; i++)
    {
        total_run += pp[i]->get_run();
        total_balls += pp[i]->get_balls();
        if (pp[i]->get_status() == 'o')
            no_of_outs++;
    }

    fstream file;
    file.open("Scorecard.txt", ios::out | ios::app);
    if(file)
    {
        file<<"\n................Generated by AHMEDxASIM....All Rights Reserved By SmartDevelopersTM....";
        file<<"\n.............................||||SCORECARD||||.................................";
        file<<"\n.............................."<<t1<<"..vs.."<<t2<<".....................................";
        file<<"\n..............................BATTING: ";
        if(ts == t1[0]) file<<t1;
        else file<<t2;
        file<<" ....................................";
        file << "\n.............................." << total_run << "/" << no_of_outs << "......." << overs << "." << overs % 6 << "...................................";
        file << "\n ___________________________________________________________________________________"
            << "\n| N |                NAME               |   R    |   B   |   4s   |   6s   |  S/R    |";
    }
    else
    {
        cout<<"\nERROR While Opening FILE, Terminating!";
        return;
    }
}

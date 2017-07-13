/*************************************************************************
	> File Name: viterbi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年06月07日 星期三 22时07分48秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

typedef vector<string> VecStr;
typedef map<string,double> MapStrDou;
typedef map<string,map<string,double>> MapStrMap;
typedef vector<string>::iterator VecStrI;
typedef map<string,double>::iterator MapStrDouI;
typedef map<string,map<string,double>>::iterator MapStrMapI;


typedef struct DSD
{
    double d1;   //总概率
    string s;
    double d2;  //最优概率
}DSD;

typedef map<string, DSD> MapStrDSD;

DSD forward_viterbi(VecStr& obs, VecStr& states, MapStrDou& start_p, MapStrMap& trans_p, MapStrMap& emit_p)
{
    MapStrDSD T;
    VecStrI VS_i, VS_j, VS_k;
    DSD DSD_tmp;
    for(VS_i=states.begin(); VS_i!=states.end(); VS_i++)
    {
        DSD_tmp.d1=start_p[*VS_i];
        DSD_tmp.s=*VS_i;
        DSD_tmp.d2=start_p[*VS_i];
        T[*VS_i]=DSD_tmp;
    }
    for(VS_i=obs.begin();VS_i!=obs.end();VS_i++)
    {
        MapStrDSD U;
        for(VS_j=states.begin(); VS_j!=states.end(); VS_j++)
        {
            double total=0.0;
            string argmax="";
            double valmax=0.0;
            double prob=1.0;
            string v_path="";
            double v_prob=1.0;
            for(VS_k=states.begin();VS_k!=states.end();VS_k++)
            {
                DSD objs=T[*VS_k];
                prob=objs.d1;
                v_path=objs.s;
                v_prob=objs.d2;
                double p=emit_p[*VS_k][*VS_i] * trans_p[*VS_k][*VS_j];
                prob*=p;
                v_prob*=p;
                total+=prob;
                if(v_prob>valmax)
                {
                    argmax=v_path+","+*VS_j;
                    valmax=v_prob;
                }
                /**test*/
                //cout<<"obs= "<<*VS_i<<endl;
                //cout<<"/tnext_sate= "<<*VS_j<<endl;
                //cout<<"/t/tstate= "<<*VS_k<<endl;
                //cout<<"/t/t/tp="<<p<<" = "<<emit_p[*VS_k][*VS_i]<<" * "<< trans_p[*VS_k][*VS_j]<<endl;
                /** end of test */
            }
            DSD_tmp.d1=total;
            DSD_tmp.s=argmax;
            DSD_tmp.d2=valmax;
            U[*VS_j]=DSD_tmp;
            cout<<"total: "<<DSD_tmp.d1<<" path: "<<DSD_tmp.s<<" p: "<<DSD_tmp.d2<<endl;;
        }
        T=U;
    }
    double total=0.0;
    string argmax="";
    double valmax=0.0;
    double prob=1.0;
    string v_path="";
    double v_prob=1.0;
    for(VS_i=states.begin(); VS_i!=states.end();VS_i++)
    {
        DSD objs=T[*VS_i];
        prob=objs.d1;
        v_path=objs.s;
        v_prob=objs.d2;
        total+=prob;
        
        if(v_prob>valmax)
        {
            argmax=v_path;
            valmax=v_prob;
        }
    }
    DSD_tmp.d1=total;
    DSD_tmp.s=argmax;
    DSD_tmp.d2=valmax;
    cout<<"return s: "<<DSD_tmp.s<<"retun p: "<<DSD_tmp.d2<<endl;
    return DSD_tmp;


}

int main()
{
    VecStr states;
    VecStr observations;
    MapStrDou start_probability;
    MapStrMap transtion_probability;
    MapStrMap emission_probability;
    states.push_back("rainy");
    states.push_back("sunny");
    observations.push_back("walk");
    observations.push_back("shop");
    observations.push_back("clean");
    start_probability["rainy"]=0.6;
    start_probability["sunny"]=0.4;
    MapStrDou t1;
    t1["rainy"]=0.7;
    t1["sunny"]=0.3;
    MapStrDou t2;
    t2["rainy"]=0.4;
    t2["sunny"]=0.6;
    transtion_probability["rainy"]=t1;
    transtion_probability["sunny"]=t2;
    MapStrDou e1;
    e1["walk"]=0.1;
    e1["shop"]=0.4;
    e1["clean"]=0.5;
    MapStrDou e2;
    e2["walk"]=0.6;
    e2["shop"]=0.3;
    e2["clean"]=0.1;
    emission_probability["rainy"]=e1;
    emission_probability["sunny"]=e2;

    DSD ret=forward_viterbi(observations,states,start_probability,transtion_probability,emission_probability);
    cout<<ret.d1<<endl;
    cout<<ret.s<<endl;
    cout<<ret.d2<<endl;

    return 0;
}









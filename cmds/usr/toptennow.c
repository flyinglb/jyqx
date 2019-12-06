// new by risc  1/4/2001
// toptennow.c
#include <ansi.h>

inherit F_CLEAN_UP;

#define TOP_CNT 10

string *skill_level = ({
        BLU "����һ��" NOR,
        BLU "��������" NOR,
        BLU "����ҳ�" NOR,
        BLU "��ѧէ��" NOR,
        HIB "�����ž�" NOR,
        HIB "��֪һ��" NOR,
        HIB "����ͨͨ" NOR,
        HIB "ƽƽ����" NOR,
        HIB "ƽ������" NOR,
        HIB "��ͨƤë" NOR,
        HIB "��������" NOR,
        HIB "������" NOR,
        HIB "����С��" NOR,
        HIB "����С��" NOR,
        HIB "�������" NOR,
        CYN "�������" NOR,
        CYN "��Ȼ���" NOR,
        CYN "���д��" NOR,
        CYN "���д��" NOR,
        CYN "��Ȼ��ͨ" NOR,
        CYN "�������" NOR,
        CYN "�޿�ƥ��" NOR,
        CYN "����Ⱥ��" NOR,
        CYN "����似" NOR,
        CYN "�����뻯" NOR,
        CYN "����Ⱥ��" NOR,
        HIC "�Ƿ��켫" NOR,
        HIC "��������" NOR,
        HIC "һ����ʦ" NOR,
        HIC "������˫" NOR,
        HIC "��������" NOR,
        HIC "������" NOR,
        HIC "��ز�¶" NOR,
        HIR "��ɲ�" NOR});

mapping *data_info = ({
(["userinfo": "-","data": 0]),
(["userinfo": "-","data": 0]),
(["userinfo": "-","data": 0]),
(["userinfo": "-","data": 0]),
(["userinfo": "-","data": 0]),
(["userinfo": "-","data": 0]),
(["userinfo": "-","data": 0]),
(["userinfo": "-","data": 0]),
(["userinfo": "-","data": 0]),
(["userinfo": "-","data": 0]),
(["userinfo": "-","data": 0]),
(["userinfo": "-","data": 0])
});

string num_to_str(int num)
{
    return num+"";
}

string to_time_str(int time)
{
    int month, day, hour, min, sec;
    sec = time % 60;time /= 60;min = time % 60;time /= 60;hour = time % 24;
    time /= 24;day = time % 30;month = time / 30;
    return (month?month + "��":"")+(day?day + "��":"")+(hour?hour + "Сʱ":"")+
           (min?min + "��":"")+(sec?sec + "��":"");
}

void insert(mapping a_data)
{
    int i,j;

    data_info[TOP_CNT]["userinfo"]=a_data["userinfo"];
    data_info[TOP_CNT]["data"]=a_data["data"];
    for (i=0;i<=TOP_CNT-1;i++)for (j=i+1;j<=TOP_CNT;j++){
        if (i==j) continue;
        if (data_info[i]["data"]<data_info[j]["data"]){
        data_info[TOP_CNT+1]["userinfo"]=data_info[i]["userinfo"];
        data_info[TOP_CNT+1]["data"]=data_info[i]["data"];
        data_info[i]["userinfo"]=data_info[j]["userinfo"];
        data_info[i]["data"]=data_info[j]["data"];
        data_info[j]["userinfo"]=data_info[TOP_CNT+1]["userinfo"];
        data_info[j]["data"]=data_info[TOP_CNT+1]["data"];
        }
    }
}

string get_sorted_list(string sort_item,string list_name,string title_name) 
{
    int i,k;string msg,tmp;object *userlist;
    mapping temp_data =(["userinfo": "-","data": 0]);
    msg="";

    for (i=0;i<TOP_CNT+1;i++){
        data_info[i]["userinfo"]="-";data_info[i]["data"]=0;
    }

    userlist=users();
    for (i=0;i<sizeof(userlist);i++){
        if (wizardp(userlist[i])) continue;
        temp_data["userinfo"]=userlist[i]->query("name")+"("+userlist[i]->query("id")+")";
        switch (sort_item){
            case "exp":     temp_data["data"]=userlist[i]->query("combat_exp");break;
            case "skills":  temp_data["data"]=sizeof(userlist[i]->query_skills());break;
            case "force":   temp_data["data"]=userlist[i]->query_skill("force",1);break;
            case "sword":   temp_data["data"]=userlist[i]->query_skill("sword",1);break;
            case "blade":   temp_data["data"]=userlist[i]->query_skill("blade",1);break;
            case "dodge":   temp_data["data"]=userlist[i]->query_skill("dodge",1);break;
            case "unarmed": temp_data["data"]=userlist[i]->query_skill("unarmed",1);break;
            case "parry":   temp_data["data"]=userlist[i]->query_skill("parry",1);break;
            case "pker":    temp_data["data"]=userlist[i]->query("PKS");break;
            case "killer":  temp_data["data"]=userlist[i]->query("PKS")+userlist[i]->query("MKS");break;
            case "age":     temp_data["data"]=userlist[i]->query("age");break;
            case "idle":    temp_data["data"]=query_idle(userlist[i]);break;
//          case "kar":     temp_data["data"]=userlist[i]->query("kar");break;
//          case "per":     temp_data["data"]=userlist[i]->query("per");break;
            case "speed_exp":temp_data["data"]=
                userlist[i]->query("combat_exp")/(userlist[i]->query("mud_age")/3600+1);break;
            case "speed_pot":temp_data["data"]=
                userlist[i]->query("potential")/(userlist[i]->query("mud_age")/3600+1);break;
            case "all":
                temp_data["data"]=userlist[i]->query("combat_exp")/(userlist[i]->query("mud_age")/3600+1);
                temp_data["data"]/=100;
                temp_data["data"]*=userlist[i]->query("potential")/(userlist[i]->query("mud_age")/3600+1);
                break;
            default:;
        }
        insert(temp_data);
    }

    for (i=0;i<TOP_CNT;i++){
        if (data_info[i]["userinfo"]=="-") 
            msg += sprintf("%-10s%-30s%-20s\n","��"+chinese_number(i+1)+"��","��","��");
        else
        switch (sort_item) {
            case "exp":
                msg += sprintf("%-10s%-30s%-20s\n",
                "��"+chinese_number(i+1)+"��",data_info[i]["userinfo"],"<����>");
                break;
            case "idle":
                msg += sprintf("%-10s%-30s%-20s\n",
                "��"+chinese_number(i+1)+"��",data_info[i]["userinfo"],to_time_str(data_info[i]["data"]));
                break;
/*
            case "kar":
                tmp=HIB+"��������"+NOR;
                if (data_info[i]["data"]>=30) tmp=HIM+"����컯"+NOR;
                else if (data_info[i]["data"]>=27) tmp=HIC+"���綫��"+NOR;
                else if (data_info[i]["data"]>=24) tmp=HIY+"�������"+NOR;
                msg += sprintf("%-10s%-30s%-20s\n",
                "��"+chinese_number(i+1)+"��",data_info[i]["userinfo"],tmp);
                break;
*/
            case "force":
            case "sword":
            case "blade":
            case "dodge":
            case "unarmed":
            case "parry":
                k=data_info[i]["data"] / 10;
                if (k>sizeof(skill_level))k=sizeof(skill_level);
                tmp=skill_level[k-1];
                msg += sprintf("%-10s%-30s%-20s\n",
                "��"+chinese_number(i+1)+"��",data_info[i]["userinfo"],tmp);
                break;
/*
            case "per":
                tmp=HIB+"��ٶ���"+NOR;
                if (data_info[i]["data"]>=30) tmp=HIM+"�绪����"+NOR;
                else if (data_info[i]["data"]>=27) tmp=HIC+"��������"+NOR;
                else if (data_info[i]["data"]>=24) tmp=HIY+"��������"+NOR;
                msg += sprintf("%-10s%-30s%-20s\n",
                "��"+chinese_number(i+1)+"��",data_info[i]["userinfo"],tmp);
                break;
*/
            case "speed_pot":
            case "speed_exp":
                msg += sprintf("%-10s%-30s%-20s\n",
                "��"+chinese_number(i+1)+"��",data_info[i]["userinfo"],num_to_str(data_info[i]["data"])+"/Сʱ");
                break;
            default:
                msg += sprintf("%-10s%-30s%-20d\n",
                "��"+chinese_number(i+1)+"��",data_info[i]["userinfo"],data_info[i]["data"]);
        }
    }

    return "������������������������������������������������������\n"
           +HIM+"��ӹȺ�� II (����)    "+BLINK+title_name+"\n"+NOR+
           "������������������������������������������������������\n"
           + HIY+sprintf("%-10s%-30s%-20s\n","��  ��","����",list_name)+NOR+
           "������������������������������������������������������\n"
           + msg +
           "������������������������������������������������������"+NOR;
}

int main(object me,string arg)
{
    string type,msg;
    if((time() - (int)me->query_temp("last_top_time") < 6) && !wizardp(me)){
        write("�㲻������ʹ�����ָ�\n");
        return 1;
    }

    if( !arg || sscanf(arg, "%s",type)!=1 )
        type="all";
        //return notify_fail("ָ���ʽ��toptennow <����>\n");
    switch (type) {
    case "exp":msg=get_sorted_list(type,"����ֵ",HIM"ʮ�����");break;
    case "skills":msg=get_sorted_list(type,"�ܼ���",HIC"��ѧ����");break;
    case "force":msg=get_sorted_list(type,"�����ڹ�",HIM"����ɽ��");break;
    case "sword":msg=get_sorted_list(type,"��������",HIC"�̽�����");break;
    case "blade":msg=get_sorted_list(type,"��������",HIY"�ֵ�����");break;
    case "dodge":msg=get_sorted_list(type,"�����Ṧ",HIW"̤ѩ�޺�");break;
    case "unarmed":msg=get_sorted_list(type,"����ȭ��",HIR"��ȭ�޵�");break;
    case "parry":msg=get_sorted_list(type,"�����м�",HIG"Ų��Ǭ��");break;
    case "pker":msg=get_sorted_list(type,"�У���",HIR"��Ѫɱ��");break;
    case "killer":msg=get_sorted_list(type,"ɱ����",HIR"��Ѫ��ħ");break;
    case "age":msg=get_sorted_list(type,"����",HIY"�ٱ���ɽ");break;
    case "idle":msg=get_sorted_list(type,"����ʱ��",HIW"����֮��");break;
//  case "kar" :msg=get_sorted_list(type,"��Ե",HIM"�����֪");break;
//  case "per" :msg=get_sorted_list(type,"��ò",HIW"����Ư��");break;
    case "speed_exp" :msg=get_sorted_list(type,"�����ٶ�",HIG"�����ٳ�");break;
    case "speed_pot" :msg=get_sorted_list(type,"Ǳ���ٶ�",HIM"ѭ�򽥽�");break;
    case "all" :msg=get_sorted_list(type,"�ۺ�����",HIR"�ۺ�����");break;
    default :return notify_fail("ָ���ʽ��toptennow <����>\n");break;
    }
    me->start_more(msg);
    me->set_temp("last_top_time",time());
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : toptennow <����>
���ָ����ʾ��ǰ������ҵ�ǰ10λ�������Ϣ��

Ŀǰ֧�ֵ������У�
all exp speed_exp speed_pot pker killer age idle
skills force sword blade dodge unarmed parry
HELP);
    return 1;
}

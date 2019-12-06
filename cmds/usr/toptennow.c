// new by risc  1/4/2001
// toptennow.c
#include <ansi.h>

inherit F_CLEAN_UP;

#define TOP_CNT 10

string *skill_level = ({
        BLU "不堪一击" NOR,
        BLU "毫不足虑" NOR,
        BLU "不足挂齿" NOR,
        BLU "初学乍练" NOR,
        HIB "初窥门径" NOR,
        HIB "略知一二" NOR,
        HIB "普普通通" NOR,
        HIB "平平淡淡" NOR,
        HIB "平淡无奇" NOR,
        HIB "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        HIB "略有小成" NOR,
        HIB "已有小成" NOR,
        HIB "驾轻就熟" NOR,
        CYN "心领神会" NOR,
        CYN "了然於胸" NOR,
        CYN "略有大成" NOR,
        CYN "已有大成" NOR,
        CYN "豁然贯通" NOR,
        CYN "出类拔萃" NOR,
        CYN "无可匹敌" NOR,
        CYN "技冠群雄" NOR,
        CYN "神乎其技" NOR,
        CYN "出神入化" NOR,
        CYN "傲视群雄" NOR,
        HIC "登峰造极" NOR,
        HIC "所向披靡" NOR,
        HIC "一代宗师" NOR,
        HIC "举世无双" NOR,
        HIC "惊世骇俗" NOR,
        HIC "震古铄今" NOR,
        HIC "深藏不露" NOR,
        HIR "深不可测" NOR});

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
    return (month?month + "月":"")+(day?day + "日":"")+(hour?hour + "小时":"")+
           (min?min + "分":"")+(sec?sec + "秒":"");
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
            msg += sprintf("%-10s%-30s%-20s\n","第"+chinese_number(i+1)+"名","—","—");
        else
        switch (sort_item) {
            case "exp":
                msg += sprintf("%-10s%-30s%-20s\n",
                "第"+chinese_number(i+1)+"名",data_info[i]["userinfo"],"<保密>");
                break;
            case "idle":
                msg += sprintf("%-10s%-30s%-20s\n",
                "第"+chinese_number(i+1)+"名",data_info[i]["userinfo"],to_time_str(data_info[i]["data"]));
                break;
/*
            case "kar":
                tmp=HIB+"祸福两分"+NOR;
                if (data_info[i]["data"]>=30) tmp=HIM+"天地造化"+NOR;
                else if (data_info[i]["data"]>=27) tmp=HIC+"福如东海"+NOR;
                else if (data_info[i]["data"]>=24) tmp=HIY+"福寿年高"+NOR;
                msg += sprintf("%-10s%-30s%-20s\n",
                "第"+chinese_number(i+1)+"名",data_info[i]["userinfo"],tmp);
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
                "第"+chinese_number(i+1)+"名",data_info[i]["userinfo"],tmp);
                break;
/*
            case "per":
                tmp=HIB+"五官端正"+NOR;
                if (data_info[i]["data"]>=30) tmp=HIM+"风华绝代"+NOR;
                else if (data_info[i]["data"]>=27) tmp=HIC+"沉鱼落雁"+NOR;
                else if (data_info[i]["data"]>=24) tmp=HIY+"俏脸生春"+NOR;
                msg += sprintf("%-10s%-30s%-20s\n",
                "第"+chinese_number(i+1)+"名",data_info[i]["userinfo"],tmp);
                break;
*/
            case "speed_pot":
            case "speed_exp":
                msg += sprintf("%-10s%-30s%-20s\n",
                "第"+chinese_number(i+1)+"名",data_info[i]["userinfo"],num_to_str(data_info[i]["data"])+"/小时");
                break;
            default:
                msg += sprintf("%-10s%-30s%-20d\n",
                "第"+chinese_number(i+1)+"名",data_info[i]["userinfo"],data_info[i]["data"]);
        }
    }

    return "———————————————————————————\n"
           +HIM+"金庸群侠 II (在线)    "+BLINK+title_name+"\n"+NOR+
           "———————————————————————————\n"
           + HIY+sprintf("%-10s%-30s%-20s\n","排  名","姓名",list_name)+NOR+
           "———————————————————————————\n"
           + msg +
           "———————————————————————————"+NOR;
}

int main(object me,string arg)
{
    string type,msg;
    if((time() - (int)me->query_temp("last_top_time") < 6) && !wizardp(me)){
        write("你不能连续使用这个指令。\n");
        return 1;
    }

    if( !arg || sscanf(arg, "%s",type)!=1 )
        type="all";
        //return notify_fail("指令格式：toptennow <类型>\n");
    switch (type) {
    case "exp":msg=get_sorted_list(type,"经验值",HIM"十大高手");break;
    case "skills":msg=get_sorted_list(type,"总技能",HIC"杂学世家");break;
    case "force":msg=get_sorted_list(type,"基本内功",HIM"气吞山河");break;
    case "sword":msg=get_sorted_list(type,"基本剑法",HIC"仗剑争锋");break;
    case "blade":msg=get_sorted_list(type,"基本刀法",HIY"持刀屠龙");break;
    case "dodge":msg=get_sorted_list(type,"基本轻功",HIW"踏雪无痕");break;
    case "unarmed":msg=get_sorted_list(type,"基本拳脚",HIR"神拳无敌");break;
    case "parry":msg=get_sorted_list(type,"基本招架",HIG"挪移乾坤");break;
    case "pker":msg=get_sorted_list(type,"ＰＫ数",HIR"冷血杀手");break;
    case "killer":msg=get_sorted_list(type,"杀生数",HIR"嗜血狂魔");break;
    case "age":msg=get_sorted_list(type,"年龄",HIY"寿比南山");break;
    case "idle":msg=get_sorted_list(type,"发呆时间",HIW"发呆之星");break;
//  case "kar" :msg=get_sorted_list(type,"福缘",HIM"天地自知");break;
//  case "per" :msg=get_sorted_list(type,"容貌",HIW"潇洒漂亮");break;
    case "speed_exp" :msg=get_sorted_list(type,"经验速度",HIG"高手速成");break;
    case "speed_pot" :msg=get_sorted_list(type,"潜能速度",HIM"循序渐进");break;
    case "all" :msg=get_sorted_list(type,"综合评价",HIR"综合评价");break;
    default :return notify_fail("指令格式：toptennow <类型>\n");break;
    }
    me->start_more(msg);
    me->set_temp("last_top_time",time());
    return 1;
}

int help(object me)
{
write(@HELP
指令格式 : toptennow <类型>
这个指令显示当前在线玩家的前10位经验等信息。

目前支持的类型有：
all exp speed_exp speed_pot pker killer age idle
skills force sword blade dodge unarmed parry
HELP);
    return 1;
}

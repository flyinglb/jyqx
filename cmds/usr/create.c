            // create.c 玩家自建门派
// byp@jyqxz 2000/09/29

#include <ansi.h>
inherit F_CLEAN_UP;

string filter_str(string str);
string conversion_color(string str);

int main(object me, string arg)
{
        string family_name, str;

        if(!wizardp(me))
                return notify_fail("该命令测试中暂时不对玩家开放。\n");

        if( !arg ) return notify_fail("你要创建什么门派？\n");
        
        //if( arg == me->query("family/family_name") )
                //return notify_fail("你自己不就是"+ me->query("family/family_name") +"的么。\n");
        
        if( !undefinedp(me->query("family/family_name")) || !me->query("chushi") )
                return notify_fail("你还没出师就想另立门户？这可是叛师的大罪啊！\n");
        
        if(me->query("combat_exp") < 8000000 )
                return notify_fail("你实战经验不够如何教导弟子？\n");
        
        if(me->query("weiwang") < 500 )
                return notify_fail("你没有点威信如何服众？\n");
        
        if(me->query("score") < 500)
                return notify_fail("你自己都没什么见识别人怎么会拜入你门下？\n");
        
        if(me->query("meili") < 100)
                return notify_fail("你的魅力不够怎么能领导他人？\n");
        
        str = filter_str(arg);

        if( strlen(str) > 10 )
                return notify_fail("你的起的门派名字太长了！换个响亮的好听点的。\n");
        
        family_name = conversion_color(arg);
        
        me->create_family(family_name, 1, "开山祖师");
        
        //记录自创门派信息
        /*log_file("player_familys",
        sprintf("family %s %s %s\n",me->name() , family_name, ctime(time())));
        */
        CHANNEL_D->do_channel(me, "rumor",
                "听说"+ me->name() +"成立了个 "+ family_name + HIR + " ，看来江湖又要多是非了！\n");
        return 1;
}

string filter_str(string str)
{
        str = replace_string(str, "$BLK$", "");
        str = replace_string(str, "$RED$", "");
        str = replace_string(str, "$GRN$", "");
        str = replace_string(str, "$YEL$", "");
        str = replace_string(str, "$BLU$", "");
        str = replace_string(str, "$MAG$", "");
        str = replace_string(str, "$CYN$", "");
        str = replace_string(str, "$WHT$", "");
        str = replace_string(str, "$HIR$", "");
        str = replace_string(str, "$HIG$", "");
        str = replace_string(str, "$HIY$", "");
        str = replace_string(str, "$HIB$", "");
        str = replace_string(str, "$HIM$", "");
        str = replace_string(str, "$HIC$", "");
        str = replace_string(str, "$HIW$", "");
        str = replace_string(str, "$NOR$", "");
        str = replace_string(str, "$HBRED$", "");
        str = replace_string(str, "$HBGRN$", "");
        str = replace_string(str, "$HBYEL$", "");
        str = replace_string(str, "$HBBLU$", "");
        str = replace_string(str, "$HBMAG$", "");
        str = replace_string(str, "$HBCYN$", "");
        str = replace_string(str, "$HBWHT$", "");
        str = replace_string(str, "$BLINK$", "");
        return str;
}

string conversion_color(string str)
{
        str = replace_string(str, "$BLK$", BLK);
        str = replace_string(str, "$RED$", RED);
        str = replace_string(str, "$GRN$", GRN);
        str = replace_string(str, "$YEL$", YEL);
        str = replace_string(str, "$BLU$", BLU);
        str = replace_string(str, "$MAG$", MAG);
        str = replace_string(str, "$CYN$", CYN);
        str = replace_string(str, "$WHT$", WHT);
        str = replace_string(str, "$HIR$", HIR);
        str = replace_string(str, "$HIG$", HIG);
        str = replace_string(str, "$HIY$", HIY);
        str = replace_string(str, "$HIB$", HIB);
        str = replace_string(str, "$HIM$", HIM);
        str = replace_string(str, "$HIC$", HIC);
        str = replace_string(str, "$HIW$", HIW);
        str = replace_string(str, "$NOR$", NOR);
        str = replace_string(str, "$HBRED$", HBRED);
        str = replace_string(str, "$HBGRN$", HBGRN);
        str = replace_string(str, "$HBYEL$", HBYEL);
        str = replace_string(str, "$HBBLU$", HBBLU);
        str = replace_string(str, "$HBMAG$", HBMAG);
        str = replace_string(str, "$HBCYN$", HBCYN);
        str = replace_string(str, "$HBWHT$", HBWHT);
//      str = replace_string(str, "$BLINK$", BLINK);
        return str + NOR;
}

int help(object me)
{
  write(@HELP
指令格式 : create <门派名称>
 
这个指令可以让你建立一个属于自己的门派。(测试中)
 
条件：首先必须要出师
      实战经验必须大于 8000000 (8M)
      江湖威望必须大于 500 
      江湖阅历必须大于 500
      魅    力必须大于 100     

 *注 请先想好你的门派名字
     对于不雅的名字巫师有权删除
 　　到一定人数时可以申请建立门派房间(人数待定)
     以上条款解释权归现任巫师组

相关命令：apprentice(bai) recruit(shou)    expell(kaichu)
          teach(jiao)     learn(xue)
          practice(lian)  research(yanjiu)
HELP
    );
    return 1;
}

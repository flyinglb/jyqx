// huqingyu.c
#include <ansi.h>
#include <command.h>
inherit NPC;

void create()
{
        set_name("胡庆余",({ "hu qingyu","hu" }));
        set("gender", "男性" );
        set("age", 63);
        set("long","胡庆余是当世一大巫医，他的本事神奇无比。真有生死肉骨之功。\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("inquiry", ([
            "改名": "好说，一百两黄金，款到即办！",
//          "叛师": "好说，一百两黄金，给你改头换面，江湖上没人会知道你的！",
//          "年龄": "这个价格嘛...!嘿嘿,一律一百两黄金年轻一岁。",
        ]) );
        set("chat_msg",({
//          "胡庆余翘着二郎腿:要想唤回你们的青春,拿出你的诚意来!!\n",
//          "胡庆余冷笑道:要叛师? 容易。快快拿出你的银子来!\n",
            "胡庆余对着你笑道：本大夫不治病，看看你还需要什么吧。\n",
            "胡庆余淡淡说道:改个名,就是新人了。\n",
        }));
        setup();
}
void init()
{
        add_action("do_name","name");
//      add_action("do_betrayer","betrayer");
//        add_action("do_age","age");
}

int accept_object(object me, object ob)
{
        if( ob->query("money_id") && ob->value() >= 1000000) {
                command("nod");
                command("say 好吧，"+me->query("name")+"你说个章程！\n");
                me->set_temp("marks/huqingyu",1);
                call_out("dest",1,ob);
                return 1;
        }
        return 0;
}

int do_name(string arg,object me)
{
        string *banned_name = ({
        "你", "我", "他", "她", "它", "巫师", "巫师测试员", "测试员", "测试",
        "时空","李凌","系统", "核心", "系统核心", "黄百家", "吃大米", "白云飘",
        "爸爸", "爷爷", "妈妈", "奶奶", "你妈", "　", 
        "蝮蛇胆", "明史辑略", "庄允城", "药粉", "订婚戒指", "水晶鞋", "小马甲",
        "玉佩", "灰狼皮", "茶叶", "金项链", "赏善铜牌", "罚恶铜牌", "小毛驴",
        });

        int i;
        me = this_player();
        if(!(int)me->query_temp("marks/huqingyu"))
                return notify_fail("胡庆余翻着黑白眼：钱呢？没给钱想占便宜？\n");
        if( !arg ) return notify_fail("胡庆余笑道：名字总该写全吧。\n");
        if( strlen(arg) > 10 )
                return notify_fail("胡庆余惊呼起来：哪有这么长的名字？\n");
        if( strlen(arg) < 4 )
                return notify_fail("胡庆余哼了一声：这么短算啥名字？\n");

        while(i--) {
                if( arg[i]<=' ' ) {
                        write("对不起，你的中文名字不能用控制字元。\n");
                        return 0;
                }
                if( (strsrch(arg, "　") >= 0) ||
                    (strsrch(arg, "爸") >= 0)) {
                        write("对不起，你的中文名字不能用引起误会的单字。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(arg[i..<0]) ) {
                        write("对不起，请您用「中文」取名字。\n");
                        return 0;
                }
        }
        if( member_array(arg, banned_name)!=-1 ) {
                write("对不起，这种名字会造成其他人的困扰。\n");
                return 0;
        }
        if( (strlen(arg) < 2) || (strlen(arg) > 10 ) ) {
                write("对不起，你的中文名字必须是 1 到 5 个中文字。\n");
                return 0;
        }

        me->delete_temp("marks/huqingyu");
        if(me->query("gender")=="女性")
                message_vision(CYN"胡大夫大笔一挥就改了$N的芳名 !真爽呆了....\n"NOR,me);
        else    message_vision(CYN"胡大夫大笔一挥就改了$N的大名..真神!!\n"NOR,me);
        me->set("name",arg);
        return 1;
}

/*
int do_betrayer(object me)
{
        me = this_player();
        
        if(!(int)me->query_temp("marks/huqingyu"))
                return notify_fail("胡庆余翻着黑白眼：钱呢？没给钱想占便宜？\n");
        me->delete_temp("marks/huqingyu");
        if (me->query("combat_exp")<10000)
                return notify_fail("真冤枉!!你的经验还可以随便叛师的! \n");
        if( me->query("betrayer") > 0 ) me->add("betrayer",-1);
        me->set("title","普通百姓");
        me->set("class","0");

        me->delete("family");
        me->delete("party");
        message_vision(CYN"胡大夫笑道: 江湖上海阔天空, 都是$N的天地了! \n"NOR,me);
        return 1;
}
*/

/*
int do_age(object me)
{
        //object obj;
        me = this_player();

        if(!(int)me->query_temp("marks/huqingyu"))
            return notify_fail("胡庆余翻着黑白眼：钱呢？没给钱想占便宜？\n");

        me->delete_temp("marks/huqingyu");
        //return notify_fail("胡庆余翻着黑白眼：年龄暂时就不考虑了！\n");

        if (me->query("mud_age")<86400)
            return notify_fail("胡大夫道: 你还很年轻的, 这一百两黄金白花了! \n");

        me->add("mud_age",-86400);
        me->add("age",-1);
        message_vision(CYN"胡大夫道: 果然有钱能使鬼推磨, $N现在看是年轻多了! \n"NOR,me);

        return 1;
} 
*/

void dest(object ob)
{
        if( !ob ) return;
        ob->move(VOID_OB);
        destruct(ob);
}

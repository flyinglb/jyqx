// hongniang.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
        set_name("红娘", ({ "hong niang","hong" }) );
        set("title", "红娘庄");
        set("gender", "女性" );
        set("age", 16);
        set("long",
                "一位明眸皓齿的小姑娘。\n");
        set("max_qi",800);
        set("max_jing",800);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("inquiry", ([
                "婚约" : "是啊……这里就可以缔结和解除婚约",
        ]) );
        set_skill("literate", 70);
        set_skill("dodge", 200);
        set_skill("unarmed", 100);
        setup();
        add_money("gold", 10);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{

        ::init();
        add_action("do_marry", "marry");
        add_action("do_unmarry", "unmarry");
}

int do_marry(string arg) {
         object obj, me;
         object *list;
        int i, have_marry;
        me = this_player();
        list = all_inventory(me);
        i = sizeof(list);
        have_marry = 0;
        if((string)me->query("gender")=="无性"){
              say("红娘笑道: 这位公公，你这不是开玩笑么？\n");
              return 1;
            }
        if ( (string)me->query("class")=="bonze")
           return notify_fail("红娘笑骂道: 你是出家人，结什么婚！你以为你是不戒和尚啊。\n");
        if ( (int)me->query("age")<17)
             return notify_fail("红娘笑道: 你年龄还小，等到十七岁再来吧。\n");
        if ( me->query("couple/couple_id"))
                return notify_fail("红娘板着脸道: 你已经结婚了吧？\n");
        if( arg == me->query("id") ) return notify_fail("红娘笑道: 和自己缔结婚约？你有病啊！\n");

        if(!arg || !objectp(obj = present(arg, environment(me)))
                || !find_player(arg)|| !find_living(arg))
        return notify_fail("红娘笑道: 你想和谁缔结良缘？\n");
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
             return notify_fail(
                "红娘笑道: 真是抱歉，请您等一下到红娘庄来找我吧。\n");

        if(obj==me) return notify_fail("红娘笑道: 和自己缔结婚约？你有病啊！\n");

        if( !living(obj) )
                return notify_fail("红娘叹口气对你说道: "+obj->name()+
                "已经无法和你缔结良缘了。\n");

        if((string)obj->query("gender")== (string)me->query("gender"))
                return notify_fail("红娘笑道: 同性恋？没听说过。\n");

        if( userp(obj) && !((object)obj->query("marks/"+me->name(1)))){
                message_vision(MAG "\n$N对著$n说道："+ RANK_D->query_self(me)
                    + me->name() + "，愿意和"+ RANK_D->query_respect(obj)
                    + "结为夫妇\n\n"NOR, me,obj);
                me->set("marks/"+obj->name(1), 1);
                tell_object(obj, MAG "如果你愿意和对方结为夫妇，请你也对"
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "下一次 marry 指令。\n" NOR);
                write(MAG "现在你急切盼望着你的心上人说同意……\n" NOR);
                return 1;
        }

        me->set("couple/have_couple",1);
        me->set("couple/couple_id", obj->query("id"));
        me->set("couple/couple_name", obj->query("name"));
        obj->set("couple/have_couple",1);
        obj->set("couple/couple_id", me->query("id"));
        obj->set("couple/couple_name", me->query("name"));
        if (me->query("gender")=="男性")
        {
                obj->set("couple/couple_gender", "丈夫");
                me->set("couple/couple_gender", "妻子");
        }
        else
        {
                me->set("couple/couple_gender", "丈夫");
                obj->set("couple/couple_gender", "妻子");
        }

        message_vision(MAG"恭喜 $N 和 $n ，一对璧人终于喜结良缘。\n"NOR,obj,me);
        CHANNEL_D->do_channel(this_object(), "chat",
                sprintf( "%s 和 %s 现在开始是夫妇啦! ",
                me->name(1), obj->name(1)));
        return 1;
}

int do_unmarry(string arg)
{
        object marry_card1, me;
        object *list,couple_ob;
        int i, have_marry;
        string tmpstr1, tmpstr2,str1,str2;
        string cardname;
        string couple_id;
        object cob;

        me = this_player();

        couple_id = me->query("couple/couple_id");
        if ( !stringp(couple_id) )
                return notify_fail("红娘笑道: 你没有伴侣。\n");

        if( !stringp(arg) || arg == "" ) arg = couple_id;
        if( arg != couple_id )
                return notify_fail("红娘笑道: 你要跟谁离婚？\n");

        list = all_inventory(me);
        i = sizeof(list);
        have_marry = 0;
        while (i--)
        {
                if (((string)list[i]->query("id")) == "marrycard")
                {
                        marry_card1 = list[i];
                        cardname = list[i]->query("name");
                        have_marry = 1;
                }
        }

        if( !environment()
        ||      base_name(environment()) != query("startroom") )
           return notify_fail("红娘笑道: 真是抱歉，请您等一下到红娘庄来找我吧。\n");

        if( file_size(DATA_DIR+"user/"+couple_id[0..0]+"/"+couple_id+__SAVE_EXTENSION__) < 0 ) {
                CHANNEL_D->do_channel(this_object(), "debug","couple id:" +couple_id + "不存在。");
                message_vision(MAG + me->query("couple/couple_name") + " 和 $N 从现在开始解除婚约!\n"NOR,me);
                CHANNEL_D->do_channel(this_object(), "chat",
                        sprintf( "聚散皆是缘，%s 和 %s 从今以后，劳燕分飞，互不相干! ",
                        me->name(1), me->query("couple/couple_name")));
                me->set("couple/have_couple",0);
                me->set("couple/couple_id", 0);

                me->set("couple/couple_name", 0);
                me->set("couple/couple_gender", 0);
                return 1;
        } else {
                if( find_player(arg) )
                        couple_ob = find_player(arg);
                else {
                        return notify_fail("红娘笑道: 你的伴侣现在不在场.\n");//debug
                        seteuid(ROOT_UID);
                        cob = new(LOGIN_OB);
                        cob->set("id",couple_id);
                        cob->restore();
                        couple_ob = LOGIN_D->make_body(cob);
                        couple_ob->restore();
                }
        }
                        
        if(couple_ob->query("couple/couple_id") != me->query("id") ) {
                CHANNEL_D->do_channel(this_object(), "debug","cob->couple id:"+couple_ob->query("couple/couple_id"));
                message_vision(MAG + me->query("couple/couple_name") + " 和 $N 从现在开始解除婚约!\n"NOR,me);
                CHANNEL_D->do_channel(this_object(), "chat",
                sprintf( "聚散皆是缘，%s 和 %s 从今以后，劳燕分飞，互不相干! ",
                me->name(1), me->query("couple/couple_name")));
                me->set("couple/have_couple",0);
                me->set("couple/couple_id", 0);
                me->set("couple/couple_name", 0);
                me->set("couple/couple_gender", 0);
                return 1;
        }
        if( !objectp(couple_ob = present(arg, environment(me))) || !find_player(arg) )
                return notify_fail("红娘笑道: 你的伴侣现在不在场.\n");

        if ((string)couple_ob->query("gender") != "女性") {
                tmpstr1 = "老婆"; tmpstr2 = "老公";
                str1 = "她"; str2 = "他";
        } else {
                tmpstr1 = "老公"; tmpstr2 = "老婆";
                str1 = "他"; str2 = "她";
        }

        list = all_inventory(couple_ob);
        i = sizeof(list);

        if( userp(couple_ob) && !((object)couple_ob->query("marks/"
                + "unmarry" +me->name(1))) )
        {
                message_vision(MAG "\n$N对著$n说道：" + RANK_D->query_self(me)
                        + me->name() + "，咱们解除婚约吧!好吗?\n\n"
                        NOR, me, couple_ob);
                me->set("marks/"+"unmarry"+couple_ob->name(1), 1);
                tell_object(couple_ob, MAG "如果你愿意解除婚约，请你也"
                        + "下一次 unmarry 指令。\n" NOR);
                write(MAG "现在你只有等着" +str2 +" 同意啦...\n" NOR);
                return 1;
        }
        me->set("couple/have_couple",0);
        me->set("couple/couple_id", 0);
        me->set("couple/couple_name", 0);
        me->set("couple/couple_gender", 0);
        couple_ob->set("couple/have_couple",0);
        couple_ob->set("couple/couple_id", 0);
        couple_ob->set("couple/couple_name", 0);
        couple_ob->set("couple/couple_gender", 0);

        message_vision(MAG" $N 和 $n 从现在开始解除婚约!\n"NOR,couple_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "聚散皆是缘，%s 和 %s 从今以后，劳燕分飞，互不相干! ",
        me->name(1), couple_ob->name(1)));

        return 1;
}

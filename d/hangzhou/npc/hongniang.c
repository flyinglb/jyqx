// hongniang.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
        set_name("����", ({ "hong niang","hong" }) );
        set("title", "����ׯ");
        set("gender", "Ů��" );
        set("age", 16);
        set("long",
                "һλ�����ݵ�С���\n");
        set("max_qi",800);
        set("max_jing",800);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("inquiry", ([
                "��Լ" : "�ǰ���������Ϳ��Ե޽�ͽ����Լ",
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
        if((string)me->query("gender")=="����"){
              say("����Ц��: ��λ���������ⲻ�ǿ���Цô��\n");
              return 1;
            }
        if ( (string)me->query("class")=="bonze")
           return notify_fail("����Ц���: ���ǳ����ˣ���ʲô�飡����Ϊ���ǲ�����а���\n");
        if ( (int)me->query("age")<17)
             return notify_fail("����Ц��: �����仹С���ȵ�ʮ���������ɡ�\n");
        if ( me->query("couple/couple_id"))
                return notify_fail("�����������: ���Ѿ�����˰ɣ�\n");
        if( arg == me->query("id") ) return notify_fail("����Ц��: ���Լ��޽��Լ�����в�����\n");

        if(!arg || !objectp(obj = present(arg, environment(me)))
                || !find_player(arg)|| !find_living(arg))
        return notify_fail("����Ц��: �����˭�޽���Ե��\n");
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
             return notify_fail(
                "����Ц��: ���Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n");

        if(obj==me) return notify_fail("����Ц��: ���Լ��޽��Լ�����в�����\n");

        if( !living(obj) )
                return notify_fail("����̾��������˵��: "+obj->name()+
                "�Ѿ��޷�����޽���Ե�ˡ�\n");

        if((string)obj->query("gender")== (string)me->query("gender"))
                return notify_fail("����Ц��: ͬ������û��˵����\n");

        if( userp(obj) && !((object)obj->query("marks/"+me->name(1)))){
                message_vision(MAG "\n$N����$n˵����"+ RANK_D->query_self(me)
                    + me->name() + "��Ը���"+ RANK_D->query_respect(obj)
                    + "��Ϊ��\n\n"NOR, me,obj);
                me->set("marks/"+obj->name(1), 1);
                tell_object(obj, MAG "�����Ը��ͶԷ���Ϊ�򸾣�����Ҳ��"
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "��һ�� marry ָ�\n" NOR);
                write(MAG "�����㼱�����������������˵ͬ�⡭��\n" NOR);
                return 1;
        }

        me->set("couple/have_couple",1);
        me->set("couple/couple_id", obj->query("id"));
        me->set("couple/couple_name", obj->query("name"));
        obj->set("couple/have_couple",1);
        obj->set("couple/couple_id", me->query("id"));
        obj->set("couple/couple_name", me->query("name"));
        if (me->query("gender")=="����")
        {
                obj->set("couple/couple_gender", "�ɷ�");
                me->set("couple/couple_gender", "����");
        }
        else
        {
                me->set("couple/couple_gender", "�ɷ�");
                obj->set("couple/couple_gender", "����");
        }

        message_vision(MAG"��ϲ $N �� $n ��һ���������ϲ����Ե��\n"NOR,obj,me);
        CHANNEL_D->do_channel(this_object(), "chat",
                sprintf( "%s �� %s ���ڿ�ʼ�Ƿ���! ",
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
                return notify_fail("����Ц��: ��û�а��¡�\n");

        if( !stringp(arg) || arg == "" ) arg = couple_id;
        if( arg != couple_id )
                return notify_fail("����Ц��: ��Ҫ��˭��飿\n");

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
           return notify_fail("����Ц��: ���Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n");

        if( file_size(DATA_DIR+"user/"+couple_id[0..0]+"/"+couple_id+__SAVE_EXTENSION__) < 0 ) {
                CHANNEL_D->do_channel(this_object(), "debug","couple id:" +couple_id + "�����ڡ�");
                message_vision(MAG + me->query("couple/couple_name") + " �� $N �����ڿ�ʼ�����Լ!\n"NOR,me);
                CHANNEL_D->do_channel(this_object(), "chat",
                        sprintf( "��ɢ����Ե��%s �� %s �ӽ��Ժ�����ַɣ��������! ",
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
                        return notify_fail("����Ц��: ��İ������ڲ��ڳ�.\n");//debug
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
                message_vision(MAG + me->query("couple/couple_name") + " �� $N �����ڿ�ʼ�����Լ!\n"NOR,me);
                CHANNEL_D->do_channel(this_object(), "chat",
                sprintf( "��ɢ����Ե��%s �� %s �ӽ��Ժ�����ַɣ��������! ",
                me->name(1), me->query("couple/couple_name")));
                me->set("couple/have_couple",0);
                me->set("couple/couple_id", 0);
                me->set("couple/couple_name", 0);
                me->set("couple/couple_gender", 0);
                return 1;
        }
        if( !objectp(couple_ob = present(arg, environment(me))) || !find_player(arg) )
                return notify_fail("����Ц��: ��İ������ڲ��ڳ�.\n");

        if ((string)couple_ob->query("gender") != "Ů��") {
                tmpstr1 = "����"; tmpstr2 = "�Ϲ�";
                str1 = "��"; str2 = "��";
        } else {
                tmpstr1 = "�Ϲ�"; tmpstr2 = "����";
                str1 = "��"; str2 = "��";
        }

        list = all_inventory(couple_ob);
        i = sizeof(list);

        if( userp(couple_ob) && !((object)couple_ob->query("marks/"
                + "unmarry" +me->name(1))) )
        {
                message_vision(MAG "\n$N����$n˵����" + RANK_D->query_self(me)
                        + me->name() + "�����ǽ����Լ��!����?\n\n"
                        NOR, me, couple_ob);
                me->set("marks/"+"unmarry"+couple_ob->name(1), 1);
                tell_object(couple_ob, MAG "�����Ը������Լ������Ҳ"
                        + "��һ�� unmarry ָ�\n" NOR);
                write(MAG "������ֻ�е���" +str2 +" ͬ����...\n" NOR);
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

        message_vision(MAG" $N �� $n �����ڿ�ʼ�����Լ!\n"NOR,couple_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "��ɢ����Ե��%s �� %s �ӽ��Ժ�����ַɣ��������! ",
        me->name(1), couple_ob->name(1)));

        return 1;
}

// huqingyu.c
#include <ansi.h>
#include <command.h>
//inherit F_CLEAN_UP
inherit NPC;

void create()
{
        set_name("������",({ "hu qingyu","hu" }));
        set("gender", "����" );
        set("age", 63);
        set("long",
"�������ǵ���һ����ҽ�����ı��������ޱȡ������������֮����\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("inquiry", ([
            "����": "��˵��һ�����ƽ𣬿���죡",
            "��ʦ": "��˵��һ�����ƽ𣬸����ͷ���棬������û�˻�֪����ģ�",
            "����": "����۸���...!�ٺ�,һ��һ�����ƽ�����һ�ꡣ",
        ]) );
        set("chat_msg",({
            "���������Ŷ�����:Ҫ�뻽�����ǵ��ഺ,�ó���ĳ�����!!\n",
            "��������Ц��:Ҫ��ʦ? ���ס�����ó����������!\n",
            "�����൭��˵��:�ĸ���,���������ˡ�\n",
        }));
        setup();
}
void init()
{
        //object ob,me;
        add_action("do_name","name");
        add_action("do_betrayer","betrayer");
        add_action("do_age","age");
}
int accept_object(object me, object ob)
{
        if( ob->query("money_id") && ob->value() >= 1000000)
        {
        command("nod");
        command("say �ðɣ�"+me->query("name")+"��˵���³̣�\n");
        me->set_temp("marks/huqingyu",1);
        return 1;
        }
}
int do_name(string arg,object me)
{
        string *banned_name = ({
                "��", "��", "��", "��", "��", "��", "��", "��", "��",
                "����ү", "������", "����", "ʱ��", "��",
                "����", "�����п�", "����", "���"
        });
        int i;

        me = this_player();
        if(!(int)me->query_temp("marks/huqingyu"))
        {
            return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�\n");
        }
        if( !arg ) return notify_fail("������Ц���������ܸ�дȫ�ɡ�\n");
        if( strlen(arg) > 10 )
        return notify_fail("�����ྪ��������������ô�������֣�\n");
        if( strlen(arg) < 4 )
        return notify_fail("���������һ������ô����ɶ���֣�\n");
        while(i--) {
                if( arg[i]<=' ' ) {
                        write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( (strsrch(arg, "��") >= 0) ||
                    (strsrch(arg, "��") >= 0)) {
                        write("�Բ�������������ֲ������������ĵ��֡�\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(arg[i..<0]) ) {
                        write("�Բ��������á����ġ�ȡ���֡�\n");
                        return 0;
                }
        }
        if( member_array(arg, banned_name)!=-1 ) {
                write("�Բ����������ֻ���������˵����š�\n");
                return 0;
        }
        if( (strlen(arg) < 2) || (strlen(arg) > 10 ) ) {
                write("�Բ�������������ֱ����� 1 �� 5 �������֡�\n");
                return 0;
        }

        me->delete_temp("marks/huqingyu");
        if (me->query("gender")=="Ů��")
        message_vision(CYN"�������һ�Ӿ͸���$N�ķ��� !��ˬ����....\n"NOR,me);
        else
        message_vision(CYN"�������һ�Ӿ͸���$N�Ĵ���..����!!\n"NOR,me);
        me->set("name",arg);

        return 1;
}

int do_betrayer(object me)
{
        me = this_player();
        if(!(int)me->query_temp("marks/huqingyu"))
        {
            return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�\n");
        }

        me->delete_temp("marks/huqingyu");
        if (me->query("combat_exp")<10000)
            return notify_fail("��ԩ��!!��ľ��黹���������ʦ��! \n");

        if(me->query("betrayer")>0)
                me->add("betrayer",-1);

        me->set("title","��ͨ����");
        me->set("class","0");
        me->delete("family");
        me->delete("party");
    message_vision(CYN"�����Ц��: �����Ϻ������, ����$N�������! \n"NOR,me);

        return 1;
}

int do_age(object me)
{
        //object obj;
        me = this_player();

        if(!(int)me->query_temp("marks/huqingyu"))
        {
            return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�\n");
        }
        me->delete_temp("marks/huqingyu");
      //return notify_fail("�����෭�źڰ��ۣ�������ʱ�Ͳ������ˣ�\n");

        if (me->query("mud_age")<864000)
            return notify_fail("������: �㻹�������, ��һ�����ƽ�׻���! \n");

        me->add("age_modify",-1);
        // me->add("age",-1);
        me->update_age();
        message_vision(CYN"������: ��Ȼ��Ǯ��ʹ����ĥ, $N���ڿ����������! \n"NOR,me);

        return 1;
} 

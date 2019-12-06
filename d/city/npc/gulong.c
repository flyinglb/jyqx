// gulong.c
inherit NPC;
#include <ansi.h>;

int do_bihua(string arg);
int do_setname(string arg);
int do_setcan(string arg);
string clear_title(string arg);
void add_title(object me,string arg);
void clear();
string ask_home();
int ask_me(string arg);
int ask_candidate();
int ask_nowcan();
int do_halt();

void create()
{
        set_name("����", ({ "gu long"}) );
        set("gender", "����");
        set("nickname", HIR"������˽"NOR);
        set("title", HIY"�������"NOR);
        set("age", 65);
        set("long",
            "����һλ���ޱ߷��Ŀ�������ˣ�һ�����ֵ�����ʮ�������׽���\n");
        set("combat_exp",1);
        set("class","scholar");
        set("shen_type", 1);
        set("attitude", "friendly");

        set("apply/attack", 200);
        set("apply/defense", 200);

        set("max_qi", 2800);
        set("max_neili", 1800);
        set("neili", 1800);
        set("max_jing", 800);

        set("win_times", 0);

        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("parry",80);
        set_skill("dodge", 80);
        set("inquiry", ([
                "������"     : (: ask_me :),
                "��ѡ��"       : (: ask_candidate :),
                "��ǰ��ѡ��"   : (: ask_nowcan:),
                "�ؼ�"         : (: ask_home:),
        ]));

        setup();
        set("candidate",this_object());
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/changjian")->wield();
}

void init()
{
        ::init();
        add_action("ask_me", "start");
        add_action("ask_candidate", "can");
        add_action("ask_nowcan", "nowcan");
        add_action("do_setname", "setname");
        add_action("do_setcan", "setcan");
        add_action("do_clearname", "clear");

        add_action("do_bihua", "fight");
        add_action("do_bihua", "hit");
        add_action("do_bihua", "kill");
        add_action("do_bihua", "bihua");
        add_action("do_bihua", "bi");
        add_action("do_halt", "halt");
}

int ask_me(string arg)
{
        string faction;
        object* ob;
        int i;
        ob = users();

        if ( !wizardp(this_player()) )
        {
            write("����Ȩ�ٿ�������!! \n");
            return 1;
        }
        switch (arg)
        {
            case "bt": 
                 faction="����ɽ��";
                 break; 
            case "em": 
                 faction="������";
                 break; 
            case "gb": 
                 faction="ؤ��";
                 break; 
            case "hs": 
                 faction="��ɽ��";
                 break; 
            case "lj": 
                 faction="���չ�";
                 break; 
            case "mj": 
                 faction="����";
                 break; 
            case "sl": 
                 faction="������";
                 break; 
            case "th": 
                 faction="�һ���";
                 break; 
            case "wd": 
                 faction="�䵱��";
                 break; 
            case "xx": 
                 faction="������";
                 break; 
            case "xs": 
                 faction="ѩɽ��";
                 break; 
            case "xy": 
                 faction="��ң��";
                 break; 
            case "yl": 
                 faction="������";
                 break; 
            default: 
                 return 1;
        }
        command("chat �ã������ĺ���̨���ޣ�"+faction+"ȫ�弯��! \n");
        for ( i=0;i<sizeof(ob); i++ )
            if((!wizardp(ob[i])) && (ob[i]->query("family/family_name")==faction))
            {
                this_object()->set("candidate",ob[i]);
                break;
            }
        for ( i=sizeof(ob); i>0; i-- )
        {
            if (ob[i-1]->query("family/family_name")==faction)
            {
                ob[i-1]->move("/d/city/wudao2");
                if(!wizardp(ob[i-1]))
                   if(ob[i-1]->query("combat_exp")>this_object()->query("candidate")->query("combat_exp"))
                     set("candidate",ob[i-1]);
            }
        }
        command("chat ����, ���ŵ�һ�ĺ�ѡ����"+this_object()->query("candidate")->query("name")+"!\n");
        command("chat ��ҿ���������ս���κ�����ʤ�峡����������������ս���ɻ�ñ��ŵ�һ�ĳƺš�\n");
        command("chat �κ�ս�ܻ���;��Ȩ�߾�ֻ��������һ�ƺš�\n");
        tell_object(this_player(),"����������: ������setname somebody ָ��ĳ��Ϊ��ǰʤ�ߡ�\n"+
               "Ҳ������setcan somebody ָ��ĳ��Ϊ��ǰ��ѡ�ˡ�\n");
        return 1;
}

int do_clearname()
{
        object* ob;
        int i;
        ob = users();

        if ( !wizardp(this_player()) )
        {
             write("����Ȩȡ���ƺ�!! \n");
             return 1;
        }
        for ( i=0;i<sizeof(ob); i++ )
             add_title(ob[i],"");
        write("��ȡ�����гƺ�!! \n");
        return 1;
}

string ask_home()
{
        this_player()->move("/d/city/guangchang");
        return("�õģ�����������ݰɡ�\n");
}

int do_bihua(string arg)
{
        object ob1, ob2;
        object old_target;

        ob1 = this_player();

        if( !arg || arg=="" ) return 0;

        if ( arg == "gu long" )
        {
             command("say " + "�㲻�ܸ��ұȻ���\n");
             return 1;
        }
        if (strsrch(ob1->query("title"), "����") >= 0)
                return notify_fail("�����������������Ҳ���㡣\n");

        if ( this_object()->query_temp("busy") )
                return notify_fail("ÿ��ֻ�������˲μӱ��䡣\n");

        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("�����˭�Ȼ���\n");

        if(wizardp(ob1)) return notify_fail("��ʦϹ���ϸ�ʲô����? \n");

        if (ob1 == ob2)  return notify_fail("�㲻�ܹ����Լ���\n");

        if (ob1->query("name")!=query("candidate")->query("name"))
        if (ob2->query("name")!=query("candidate")->query("name"))
                return notify_fail("��ֻ�����ѡ����ս��\n");

        if (ob2->query("family/family_name")!=ob1->query("family/family_name"))
                return notify_fail("�ֲ��������ɵĪ����¸�ɶ���ء�\n");

        if (ob1->query_temp("lose")*5>query("win_times"))
                return notify_fail("���Ѿ����һ���˪�ֻ������һ��ѡ����ս��\n");

        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N����$n˵����"
                        + RANK_D->query_self(ob1)
                        + ob1->name() + "�����"
                        + RANK_D->query_respect(ob2)+"�ĸ��Т�\n\n", ob1, ob2);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "�����Ը��ͶԷ����б��Ԫ�����Ҳ��" + ob1->name() + "("+(string)ob1->query("id")+")"+ "��һ�� bihua ָ�\n" NOR);

                write(YEL "��춶Է�������ҿ��Ƶ����窱�����ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
                return 1;
        }

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");

        remove_call_out("check");
        call_out("check",2, ob1, ob2);

        ob1->set("qi",(int)ob1->query("max_qi"));
        ob2->set("qi",(int)ob2->query("max_qi"));

        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);

        return 1;
}

void fighting(object ob1, object ob2)
{
        ob1->fight_ob(ob2);
        ob2->fight_ob(ob1);
}

void check(object ob1, object ob2)
{
        this_object()->set_temp("busy",1);
        command("chat " + ob1->query("name")
                + "��" + ob2->query("name") + "�������ĺ��޿�ʼ�����۽���\n");
        command("chat ��ǰ��ѡ��"+query("candidate")->query("name")+"�ѻ�ʤ"+(string)(query("win_times")%5)+"��.\n");
        call_out("observe",1,ob1,ob2);
}

int observe(object ob1,object ob2)
{

        if(ob2->query("name")!=query("candidate")->query("name"))
        {
                call_out("observe",0,ob2,ob1);
                return 1;
        }

        if(ob1->is_fighting())
        {
                call_out("observe",1,ob1,ob2);
                return 1;
        }

        this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");

        if ( !present(ob1, environment()) )
        {
                command("chat " + ob1->query("name") + "��Ķ����ˣ�\n");
                command("chat " + ob2->query("name")
                        + "����սʤ" + ob1->query("name") + "��\n");

                add("win_times",1);
                if(this_object()->query("win_times")==10)
                {
                        command("chat " + ob2->query("name")
                                + "��ñ��α����᱾�ŵڶ��ĳƺţ�\n");
                        add_title(ob2,"���ŵڶ�");

                        command("chat �����������\n");
                        this_object()->delete("candidate");
                        this_object()->delete("win_times");
                        return 1;
                }
                if(this_object()->query("win_times")==5)
                {
                        command("chat "+ob2->query("name")
                                + "��ñ��α����᱾�ŵ�һ�ĳƺţ�\n");
                        add_title(ob2,"���ŵ�һ");
                        command("chat ����, ���ŵڶ��ĺ�ѡ����"
                                + ob1->query("name")+"��\n");
                        command("chat ��ҿ���������ս���κ�����ʤ�峡��������
��������ս���ɻ�ñ��ŵڶ��ĳƺš�\n");
                        set("candidate",ob1);
                }
                return 1;
        }

        if ( !present(ob2, environment()) )
        {
                command("chat " + ob2->query("name") + "��Ķ����ˣ�\n");
                command("chat " + ob1->query("name")
                        + "����սʤ" + ob2->query("name") + "��\n");
                if(query("win_times")<5)
                {
                        command("chat "+ob1->query("name")
                                + "��Ϊ���ŵ�һ֮��ѡ�ˣ�\n");
                        set("win_times",0);
                }
                else
                {
                        command("chat "+ob1->query("name")
                                + "��Ϊ���ŵڶ�֮��ѡ�ˣ�\n");
                        set("win_times",5);
                }
                set("candidate",ob1);
                ob2->add_temp("lose",1);
                return 1;
        }

        if (ob1->query_temp("halted"))
        {
                ob1->delete_temp("halted");
                command("chat " + ob1->query("name") +
                        "��;�������䣡\n");
                command("chat " + ob2->query("name")
                        + "����սʤ" + ob1->query("name") + "��\n");
                add("win_times",1);
                ob1->add_temp("lose",1);
                if(this_object()->query("win_times")==10)
                {
                        command("chat " + ob2->query("name")
                                + "��ñ��α����᱾�ŵڶ��ĳƺţ�\n");
                        add_title(ob2,"���ŵڶ�");
                        command("chat �����������\n");
                        this_object()->delete("candidate");
                        this_object()->delete("win_times");
                        return 1;
                }
                if(this_object()->query("win_times")==5)
                {
                        command("chat " + ob2->query("name")
                                + "��ñ��α����᱾�ŵ�һ�ĳƺţ�\n");
                        add_title(ob2,"���ŵ�һ");
                        command("chat ����, ���ŵڶ��ĺ�ѡ����"
                                + ob1->query("name")+"��\n");
                        command("chat ��ҿ���������ս���κ�����ʤ�峡��������
��������ս���ɻ�ñ��ŵڶ��ĳƺš�\n");
                        set("candidate",ob1);
                }
                return 1;
        }
        if (ob2->query_temp("halted"))
        {
                ob2->delete_temp("halted");
                command("chat " + ob2->query("name") +
                        "��;�������䣡\n");
                command("chat " + ob1->query("name")
                        + "����սʤ" + ob2->query("name") + "��\n");
                if(query("win_times")<5)
                {
                        command("chat "+ob1->query("name")
                                + "��Ϊ���ŵ�һ֮��ѡ�ˣ�\n");
                        set("win_times",0);
                }
                else
                {
                        command("chat "+ob1->query("name")
                                + "��Ϊ���ŵڶ�֮��ѡ�ˣ�\n");
                        set("win_times",5);
                }
                set("candidate",ob1);
                ob2->add_temp("lose",1);
                return 1;
         }

        if ( ob1->query("qi")*2 > ob1->query("max_qi"))
        {
                if  (ob2->query("qi")*2 > ob2->query("max_qi"))
                {
                        command("chat " + ob1->query("name")
                                + "��" + ob2->query("name") + "���䲻��ʤ����\n");
                        return 1;
                }
                command("chat " + ob1->query("name")
                        + "����սʤ" + ob2->query("name") + "��\n");
                if(query("win_times")<5)
                {
                        command("chat "+ob1->query("name")
                                + "��Ϊ���ŵ�һ֮��ѡ�ˣ�\n");
                        set("win_times",0);
                }
                else
                {
                        command("chat "+ob1->query("name")
                                + "��Ϊ���ŵڶ�֮��ѡ�ˣ�\n");
                        set("win_times",5);
                }
                set("candidate",ob1);
                ob2->add_temp("lose",1);
                return 1;
        }
        else
        {
                command("chat " + ob2->query("name")
                        + "����սʤ" + ob1->query("name") + "��\n");
                add("win_times",1);
                ob1->add_temp("lose",1);
                if(this_object()->query("win_times")==10)
                {
                        command("chat " + ob2->query("name")
                                + "��ñ��α����᱾�ŵڶ��ĳƺţ�\n");
                        add_title(ob2,"���ŵڶ�");
                        command("chat �����������\n");
                        this_object()->delete("candidate");
                        this_object()->delete("win_times");
                        return 1;
                }
                if(this_object()->query("win_times")==5)
                {
                        command("chat " + ob2->query("name")
                               +"��ñ��α����᱾�ŵ�һ�ĳƺţ�\n");
                        add_title(ob2,"���ŵ�һ");
                        command("chat ����, ���ŵڶ��ĺ�ѡ����"
                                + ob1->query("name")+"��\n");
                        command("chat ��ҿ���������ս���κ�����ʤ�峡��������
��������ս���ɻ�ñ��ŵڶ��ĳƺš�\n");
                        set("candidate",ob1);
                        return 1;
                }
        }
        return 1;
}

int do_halt()
{
        object me = this_player();
        if (me->is_fighting()) me->set_temp("halted",1);
        return 0;
}


int do_setcan(string arg)
{
        object ob;
        if(!wizardp(this_player())) return notify_fail("����Ȩ�趨��ѡ��!\n");
        if(!arg||!objectp(ob=present(arg,environment(this_player()))))
                return notify_fail("����˵: �Բ��𣬴��˲������\n");
        set("candidate",ob);
        command("nod");
        command("chat ��ǰ��ѡ����"+query("candidate")->query("name")+"��\n");
        return 1;
}

int ask_nowcan()
{
        write("��ǰ��ѡ����"+(query("candidate")->query("name"))+"��\n");
        return 1;
}

int ask_candidate()
{
        object* ob,obj;
        int i;
        ob = users();

        if ( !wizardp(this_player()) )
        {
            write("����Ȩ��ѯ��ѡ��! \n");
            return 1;
        }
        for ( i=0;i<sizeof(ob); i++ )
            if(!wizardp(ob[i]))
            {
                if(!(strsrch(ob[i]->query("title"), "����") >= 0))
                {
                    obj=ob[i];
                    break;
                }
            }
        for ( i=sizeof(ob); i>0; i-- ) {
                if(!wizardp(ob[i-1]))
                if(!(strsrch(ob[i-1]->query("title"), "����") >= 0))
                if(ob[i-1]->query("combat_exp")>query("candidate")->query("combat_exp"))
                obj=ob[i-1];
        }
        write("��һ��ѡ����"+obj->query("name")+"��\n");
        return 1;
}

string clear_title(string arg)
{
        if( (strsrch(arg, "���ŵ�һ") >= 0) ||
            (strsrch(arg, "���ŵڶ�") >= 0) )
                {
                arg = replace_string(arg, "���ŵ�һ","");
                arg = replace_string(arg, "���ŵڶ�","");
        }
        return arg;
}

void add_title(object me,string arg)
{
        string title;
        title=arg+clear_title(me->query("title"));
        me->set("title",title);
}

int do_setname(string arg)
{
        object dest,*all;
        int i,losetime;

        if (!wizardp(this_player())) return notify_fail("����Ȩ�趨�ƺ�! \n");
        all = users();

        for(i=0; i<sizeof(all); i++)
        {
                if(arg == all[i]->name() || arg == all[i]->query("id") )
                        dest = all[i];
        }
        if( !dest )
                return notify_fail("����˵���Բ��𣬴���Ҳ������\n");
        if (dest->is_ghost())
                return notify_fail("����˵���Բ��𣬴����Ѿ����ˡ�\n");
        if(this_object()->query("win_times")==5)
        {
                command("chat " + dest->query("name")
                        + "��ñ��α����᱾�ŵڶ��ĳƺ�!\n");
                add_title(dest,"���ŵڶ�");
                command("chat ���������!\n");
                this_object()->delete("candidate");
                this_object()->delete("win_times");
        }
        else if(this_object()->query("win_times")==0)
        {
                command("chat " + dest->query("name")
                        + "��ñ��α����᱾�ŵ�һ�ĳƺ�!\n");
                add_title(dest,"���ŵ�һ");
                set("win_times",5);
                command("chat ���ڴ�ҿ���������ս�����᱾�ŵڶ���\n");
                losetime=1;
        }
        for(i=0; i<sizeof(all); i++)
                all[i]->set_temp("lose",losetime);
        return 1;
}


// zhu.c ����

inherit NPC;
inherit F_DEALER;
#include <ansi.h>

string * degree_desc = ({
       BLU "��ä" NOR,
       BLU "ͯ��" NOR,
       BLU "���" NOR,
       CYN "����" NOR,
       CYN "��Ԫ" NOR,
       CYN "��ʿ" NOR,
       CYN "��Ԫ" NOR,
       GRN "��ʿ" NOR,
       GRN "̽��" NOR,
       GRN "����" NOR,
       GRN "״Ԫ" NOR,
       HIY "����Ժʿ" NOR,
       HIY "����˶ʿ" NOR,
       HIY "���ֲ�ʿ" NOR,
       HIY "����Ժ����" NOR,
       HIR "����ʿ" NOR,
       HIR "ѧʿ" NOR,
       HIR "�ڸ��ѧʿ" NOR,
       HIR "�ڸ��׸�" NOR,
       MAG "��ѧ����ʦ" NOR,
       HIW "ʥ��" NOR,
});

string ask_buy();
int ask_degree();
void destroy(object ob);
void create()
{
        set_name("����", ({ "zhu xi", "zhu" }));
        set("long",
"����������Ϊ������һ����ѧ�ң��������īˮ�Ⱥ���Ҫ�\n");
        set("gender", "����");
        set("age", 65);
        set("no_get", 1);
        set_skill("literate", 300);
        set_skill("taoism", 250);  //����ҲӦ���������������?--Simon

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        set("inquiry", ([
            "ѧλ" : (:ask_degree:),
            "����" : (:ask_buy:),
            "��"   : "��!�鵽��ʱ�����١�",
            "����" : "�裿�㲻���ҵ��������㣿��!",
        ]));
        set("vendor_goods", ({
		"/clone/book/lbook1",
		"/clone/book/lbook2",
		"/clone/book/lbook3",
		"/clone/book/lbook5",
		"/clone/book/lbook6",
		"/clone/book/lbook7",
		"/clone/book/lbook8"
        }));
        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
                "����˵��������֮�£�Ī������������֮����Ī��������\n",
                "����˵���������ˣ�С�������ɣ����������δ������֮��\n",
                "����˵������ѧ֮�����������¡���������ֹ�����ơ� \n",
                "����˵����������֪���������ģ�������ң��ι�ƽ���¡�\n",
        }) );
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/��"))
                return 0;
        ob->add_temp("mark/��", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        object me = this_player();
        if (!(int)who->query_temp("mark/��"))
                who->set_temp("mark/��", 0);
        if (ob->query("money_id") && ob->value() >= 1000) {
                message_vision("����ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
                call_out("destroy",1,ob);
                who->add_temp("mark/��", ob->value() / 50);
        if( me->query_skill("literate", 1) > 21){
        tell_object(me,"����������һ�����Ļ�֪ʶ,Ҳ�����Լ����������ˡ�\n");
        return 1;}
                return 1;
         }
}

string ask_buy()
{
//      int i;
        return "������в��ٶ����˱ض�����Ӵ!\n";
//        i = (int)me->query_temp("ask_book");
}

void init()
{
        add_action("do_list","list");
         add_action("do_buy", "buy");
        return ;
}
int ask_degree()
{
        int lv;
        object ob = this_player();
        lv = (ob->query_skill("literate") / 5);
        if (lv >= sizeof(degree_desc)) lv = sizeof(degree_desc)-1; 
        if (lv < 3) 
        {
               command("say "+ob->query("name")+"�����ǵ�īˮҲ����˼��? �������ѧλ������! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
        if (lv < 10) 
        {
               command("say "+ob->query("name")+"������������ǰ;���ܸ�������ѧλ���㣬�����ú�Ŭ��! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
        else
        {
               command("say ��Ȼ�ǳ���������ǰ�˰���"+ob->query("name")+"���ҷǳ��������л���Ϊ����ѧλ! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
}

void destroy(object ob)
{
        if(!ob) return;
        ob->move(VOID_OB);
        destruct(ob);
}

// Jay 3/17/96
inherit NPC;
void create()
{
        set_name("����", ({ "su pu", "su"}));
        set("gender", "����");
        set("age", 23);
        set("long", "һ������Ĺ�����������, �����˵�һ��ʿ��³�˵Ķ��ӡ�\n");
        set("attitude", "friendly");
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("shen", 3000);
        set("str", 36);
        set("int", 20);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 600);
        set("max_jing", 600);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 20);
        set_skill("unarmed", 60);
        set_skill("blade", 80);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_temp("apply/damage", 30);
        set("inquiry", ([
            "����" : "����������! ��ô��? ����? ����ˤˤ�ӡ�\n",
            "������" : "̾,��֪�����Ķ�ȥ�ˡ���ô������һֱû����������\n",
            "������" : "�����˻����������ҵ����ƣ���ҽţ����ƥ�ļ�����\n",
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"�����Ժ����µ�: �ҵ��ǹ����˵�һ��ʿ��\n",
"������������: ���Ķ�ȥŪһ���ϵȵ���Ƥ, �͸�������? \n",
        }) );
        carry_object(__DIR__"obj/duandao")->wield();
        carry_object(__DIR__"obj/ycloth")->wear();
}
int accept_object(object who, object ob)
{
        object maotan;
         maotan = new(__DIR__"obj/maotan");
        if ((string)ob->query("name")=="����Ƥ")
           {
             say(
"����˵����лл! лл! ����ë̺����ˤ��ʤɣ˹���õĽ�Ʒ, �͸����Ա����⡣\n"
"���հ�" + maotan->query("name") + "������" + who->query("name") + "��\n");
             maotan->move(who);
        call_out("destroy", 1, ob);
        return 1;
        }
        return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

// Jay 3/17/96
inherit NPC;
void create()
{
        set_name("������", ({ "ji laoren", "ji"}));
        set("gender", "����");
        set("age", 70);
        set("long", 
"��ͷ�׷�������һ���Ǻڵģ�������Ǹߴ�ֻ�ǹ���������˥���Ѽ���\n"
"������Ÿ����̴��������ɡ��ɡ����س����̡�\n");
        set("attitude", "friendly");
        set("combat_exp", 10000);
        set("shen_type", 1);
        set("shen", 1000);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 24);
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 10);
        set_skill("unarmed", 50);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 15);
        set("inquiry", ([
            "������" : "�⺢�������ࡣ\n",
            "��������" : "������������������ҵ����ơ�\n",
            "�̲�" : "��Ҫ�̲ݣ���ҲҪ�õ㶫�������ɣ�\n"
                     "������̫���ˣ������ﲻ���ˡ�\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/ycloth")->wear();
        carry_object(__DIR__"obj/hanyan")->wield();
}
int accept_object(object who, object ob)
{
        if ((string)ob->query("id")=="maotan") {
        message_vision(
        "�����˵����ͷ, ˵����лл! ����������Ҵӽ��ϴ�����, ���͸���ɡ�\n�����˰ѽ��뽻����$N��\n", who);
        new(__DIR__"obj/jinzhen")->move(who);
        call_out("destroy", 1, ob);
        return 1;
        }

        if ((string)ob->query("id")=="youtan flower") {
        message_vision(
        "�����˵����ͷ, ˵����лл! �벻����λ" + RANK_D->query_respect(who)+ "Ҳ��ͬ��, ���̲ݾ��͸���ɡ�\n�����˰��̲ݽ�����$N��\n", who);
        new(__DIR__"obj/yancao")->move(who);
        return 1;
        }
        return 0;
}


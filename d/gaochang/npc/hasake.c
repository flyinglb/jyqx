// Jay 3/17/96
inherit NPC;
void create()
{
        set_name("��������", ({ "hasake", "ren"}));
        set("gender", "����");
        set("age", 26);
        set("long", "һ�������������꣬���ż�ʮֻ��\n");
        set("attitude", "friendly");
        set("combat_exp", 4000);
        set("shen_type", 0);
        set("str", 32);
        set("int", 18);
        set("con", 22);
        set("dex", 17);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set_skill("unarmed", 20);
        set_skill("blade", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_temp("apply/damage", 25);
        
        set("inquiry", ([
            "����" : "ѽ, ��ҲҪ������ˤ��?  ��������ͻ��ҵ�����\n",
            "����" : "̾, ��ˤ����Ӯ�������ա�\n",
            "������" : "�����˻����������ҵ����ƣ���ҽţ����ƥ�ļ�����\n",
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"�������˸��˵�˵: �ϸ��£����õ�������һͷ�ǣ�������Ƥ�͸��۰��á�\n",
"�������˵�:  �����ǲ�ԭ��һ�����·�Ļ���\n",
        }) );
        carry_object(__DIR__"obj/duandao")->wield();
        carry_object(__DIR__"obj/ycloth")->wear();
}

// diaoyu.c

inherit NPC;

void create()
{
        set_name("������", ({ "fishman","diao" }) );
        set("gender", "����" );
        set("age", 58);
        set("long","һ��������˸�����ߣ������ֳֵ��ͣ����������ϣ����н�̫��֮�硣\n");
        set("shen_type", 1);
        set("combat_exp", 4000);
        set("str", 15);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}


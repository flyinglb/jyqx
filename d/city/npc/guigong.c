// guigong.c
inherit NPC;

void create()
{
        set_name("�깫", ({ "gui gong", "gui", "gong" }));
        set("gender", "����");
        set("age", 25);

        set("long", "һ����������ĺ��ӣ�������Ժ���Ӿ��ˣ����İװ׷ʷʡ�\n");
        set("combat_exp", 30000);
        set("shen_type", 2);
        set_skill("unarmed", 70);
        set_skill("dodge", 70);
        set("chat_msg", ({
             "С��Ƥ����������͹ԹԵ��̺��ү�ǰɡ�",
             "���ܣ��ܵ����ĺ��Ƕ�����׷������",
             "�ߣ�������ЩС���ˣ���ã�",
        }) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

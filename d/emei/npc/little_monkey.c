// little_monkey.c

inherit NPC;

void create()
{
        set_name("С��",({ "little monkey", "monkey"}) );
        set("gender", "����" );
        set("age", 7);
        set("long", "����һֻ��Ƥ��С���ӣ�����������ȴϲ��ģ��������\n");
        set("combat_exp", 50);
//        set("shen", 50);
        set("shen_type", -1);
        set("str", 11);
        set("dex", 11);
        set("con", 11);
        set("int", 11);
        set("attitude", "peaceful");
        setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}

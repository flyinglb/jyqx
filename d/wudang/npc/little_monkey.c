// little_monkey.c

inherit NPC;

void create()
{
	set_name("С��",({ "little monkey", "monkey"}) );
	set("gender", "����");
	set("race", "Ұ��");
	set("age", 1);
	set("long", "����һֻ��Ƥ��С���ӣ�����������ȴϲ��ģ��������\n");
        set("limbs", ({ "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
	set("combat_exp", 500);
	set("shen_type", -1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "peaceful");

        set("water", 200);
        set("food", 200);

        set("chat_chance", 10);
        set("chat_msg", ({
                "С���Ӻ�Ȼ���˹�����һ��������ǰצһ��ժ����Ĳ�ñ!\n",
                "С���Ӻ��һ��һ�����������������������������һ����!\n",
        }) );


        setup();
}

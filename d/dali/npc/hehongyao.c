// hehongyao.c

inherit NPC;

void create()
{
	set_name("�κ�ҩ",({ "he hongyao", "he" }) );
        set("gender", "Ů��" );
        set("age", 47);
        set("long", "��Ů�˾���������ţ���ͷ���棬ͷ���ҵ����ѣ�ʮָ����
��צ������������ֵ��˺ۣ������Ǳ�����˺ҧ���£��˺���
�ڲ�����Ŀ��\n");
 	set_temp("apply/defense", 5);
	set("combat_exp", 70000);
	set("shen_type", -1);
        set("per", 12);
        set("str", 34);
        set("dex", 35);
        set("con", 36);
        set("int", 35);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
        set("attitude", "friendly");
        setup();
}


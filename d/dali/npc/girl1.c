// girl1.c

inherit NPC;

void create()
{
	set_name("�Ϲ�����",({ "girl" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("long", "�Ϲ��Ĵ�����Ĵ��е�����������ɽˮ�ķ��ϣ������Ц������
����������������Ű�ɫ���£���ɫ�Ŀ�㣬�������ź�˿����ӣ�
ͷ�ϲ��Ų�ɫ��ͷ��\n");
 	set_temp("apply/defense", 15);
	set("combat_exp", 2000);
	set("shen_type", 1);
        set("per", 25);
        set("str", 24);
        set("dex", 25);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/whitecloth1")->wear();
}


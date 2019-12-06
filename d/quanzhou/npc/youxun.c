// youxun.c
// pal 1997.05.28

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

int ask_news();
int ask_meeting();

void create()
{
        set_name("��Ѷ", ({ "you xun", "you", "xun" }) );
        set("nickname", "��������");
        set("gender", "����" );
        set("age", 42);
        set("long",
                "������ר�Ŵ�̽��������Ϣ����Ѷ��\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");

	set("max_jing",500);
	set("max_qi",500);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);

        set("inquiry", ([
		"name" : "С�ľ�����Ѷ����֪��Ҫ������ʲô��",
//		"hop"  : "����������ѽ������һλ����Ů��, ���м�����ɫ. �������Ŵ��˵㡣",
//		"wind" : "�����ʷ���ѽ�����ǽ�ӹȺ������һ���������뵱��һ��ƽ���£��ε����硣\n��񹦳����ˣ�����ɽ�ȣ���˵��Ǳ����һЩĻ����ơ�",
//		"tellmewhy" : "������С־ѽ���������Ӧ�Ƶ�һλС������ס�ˣ�Ҳ�����ı�̣�\nһ����ϺΪ����������......\n",
		"ŷұ��"  : "���ʿ��԰�����������ŷұ��ү��ѽ����˵�����ڴ���ͽ�ܵ�����ȥ\n��ס�ˣ�����˵�����ڱ��¸����ˣ�Ҳ��֪���\n",
		"news" : (: ask_news :),
		"meeting" : (: ask_meeting :),
		"����" : (: ask_news :),
		"������" : (: ask_meeting :),
        ]) );

        set_skill("literate", 100);
        set_skill("dodge", 500);
        set_skill("unarmed", 300);
        setup();
        add_money("gold", 5);
	carry_object("d/city/obj/cloth")->wear();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( environment(ob) != environment() ) return;
	command("hi "+ob->query("id"));
}

int ask_news()
{
	int rows;
	string temp;

	temp = read_file(__DIR__"news.txt", 2, 1);
	rows = atoi(temp);
	temp = read_file(__DIR__"news.txt", 3, rows);
	temp = "��Ѷ˵����\n"+temp+"\n";
	write(temp);

	return 1 ;

}

int ask_meeting()
{
	int rows;
	string temp;

	temp = read_file(__DIR__"meeting.txt", 2, 1);
	rows = atoi(temp);
	temp = read_file(__DIR__"meeting.txt", 3, rows);
	temp = "��Ѷ˵����\n"+temp+"\n";
	write(temp);

	return 1 ;

}

// /u/beyond/mr/matou.c
// this is made by beyond
// updated by Jpei  1999.9.7

inherit ROOM;

#include <ansi.h>  

mapping *sign=({
([
	"name":"����С��",
        "id":"mr",
        "file":__DIR__"duchuan",
	"value":500
]),
([
	"name":"������",
	"id":"yanziwu",
	"file" :__DIR__"zhou",
	"value":1000
]),
});

string look_sign();
int do_go(string);

void create()
{
        set("short", "��ͷ");
	set("long",@LONG
������Ľ�ݼҵļ��ͺ�Ѿ�߳���̫����ˮ����ͷ��ֻ����������������
һ�����糾���ͣ���ͷ�ߵ��ϴ���������߹���������Ц�Ǻǵ�ӭ����ȥ��
�۸��(sign)��
LONG 
);
	set("outdoors","mr");
	set("exits",([
		"north" : __DIR__"shiqiao",
	]));
	set("item_desc", ([
		"sign" : (: look_sign :)
	]));
//	set("outdoor", "abc");

	setup();
}

void init()
{
	add_action("do_go", ({ "qu", "dao" }));
}

string look_sign()
{
	object ob = this_player();
	string str="";
	int i=sizeof(sign);

        if (ob->query("family/family_name") != "����Ľ��") i--;

	while (i--) {
		str += sign[i]["name"];
		str += "(" + sign[i]["id"] + ") ";
	        if (ob->query("family/family_name") == "����Ľ��")
			str += "Ľ�ݵ������\n";
		else
			str += MONEY_D->price_str(sign[i]["value"]) + "\n";
	}

	return str;
}

void do_move(object ob, int i)
{
        if (ob->query("family/family_name") == "����Ľ��")
		message_vision(YEL"\n$N���Ŵ�������һ��С�ۡ�\n\n"NOR,ob);
	else
		message_vision(YEL"\n$N��Ǯ�������ң�������$N����һ��С�ۡ�\n\n"NOR,ob);
	ob->move(sign[i]["file"]);
}

int do_go(string arg)
{
	object ob=this_player();
	int level1, level2, i=sizeof(sign);
	string skill;

	if (!arg) return notify_fail("��Ҫȥ���\n");
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("����æ���أ�\n");

//	if (ob->query("family/family_name") != "����Ľ��") i--;

	while(i--) {
		if (arg == sign[i]["id"]) {
		        if (ob->query("family/family_name") == "����Ľ��") {
				level1 = ob->query_skill("xingyi-zhang", 1);
				level2 = ob->query_skill("canhe-zhi", 1);
				if (!level1 && !level2) skill = "���ӳ���";
				else if (level1 > level2) skill = SKILL_D("xingyi-zhang")->query_skill_name(random(level1));
				else skill = SKILL_D("canhe-zhi")->query_skill_name(random(level2));
				message_vision("$N�򴬼Ҵ��˸�Ҿ��������λ���ң�����Ľ�ݵ��ӣ���ȥ" + sign[i]["name"] + "����\n",ob);
				message_vision("���ҿ��˿�$N��¶�����ɵ���ɫ��\n",ob);
				message_vision("$N��¶΢Ц��ʹ��һ�С�" + skill + "������������Σ���\n���ҵ��˵�ͷ����������������\n",ob);
				ob->start_busy(1);
				call_out("do_move", 1, ob, i);
			}
			else {
				switch (MONEY_D->player_pay(ob, sign[i]["value"])) {
					case 0:
						return notify_fail("��⵰��һ�ߴ���ȥ��\n");
					case 2:
						return notify_fail("����Ǯ��\n");
				}
				message_vision("$N�ڿڴ��﷭����ȥ���Ҵ�Ǯ��\n", ob);
				ob->start_busy(3);
				call_out("do_move", 3, ob, i);
			}
			return 1;
		}
	}
	return notify_fail("��Ҫȥ���\n");
}


// /u/beyond/mr/anbian1.c
// this is made by beyond
// updated by Jpei  1998.9.7

#include <room.h>
#include <ansi.h>

inherit ROOM;

mapping *paizi=({
([  
	"name":"����С��",
	"id":"xiaozhu",
        "file":__DIR__"zhou6",                    
        "value":500
]),
([  
	"name":"������",
        "id":"yanziwu",
        "file":__DIR__"zhou",
	"value":500
]),               
});

string look_paizi();
int do_go(string);

void create()
{
	set("short",HIY"����"NOR);
	set("long", @LONG
������٢��ɽׯ��һ��С��ͷ���������ϴ����Ե���Ľ�����ҵ���أ�
�����е�Ӣ�ۺ����Ƕ�ʮ����Ľ�������µ������룬��Ϊ���������˲�֪��
�˲����ġ��Ա�֮������ʩ�����ķ�Դ�أ���Ľ������һ������ס�����
������һλ�ϴ���ר������ȥ�������������ʿ����һ�����߹���������
����������Ц����æӭ��ǰȥ���ڰ�����һ������(paizi)��
LONG
);
	set("outdoors","mr");
	set("exits",([
		"north" : __DIR__"xiaojing1-0",
	]));
	set("item_desc",([
		"paizi" : (: look_paizi :)     
	]));
}

void init()
{
	add_action("do_go", ({ "qu", "dao" }));
}

string look_paizi()
{
	object ob = this_player();
	string str="";
	int i=sizeof(paizi);

//	if (ob->query("family/family_name") != "����Ľ��") i--;

	while (i--) {
		str += paizi[i]["name"];
		str += "(" + paizi[i]["id"] + ") ";
	        if (ob->query("family/family_name") == "����Ľ��")
			str += "Ľ�ݵ������\n";
		else
			str += MONEY_D->price_str(paizi[i]["value"]) + "\n";
	}

	return str;
}

void do_move(object ob, int i)
{
        if (ob->query("family/family_name") == "����Ľ��")
		message_vision(YEL"\n$N���Ŵ�������һ��С�ۡ�\n\n"NOR,ob);
	else
		message_vision(YEL"\n$N��Ǯ�������ң�������$N����һ��С�ۡ�\n\n"NOR,ob);
	ob->move(paizi[i]["file"]);
}

int do_go(string arg)
{
	object ob=this_player();
	int level1, level2, i=sizeof(paizi);
	string skill;

	if (!arg) return notify_fail("��Ҫȥ���\n");
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("����æ���أ�\n");

//	if (ob->query("family/family_name") != "����Ľ��") i--;

	while(i--) {
		if (arg == paizi[i]["id"]) {
		        if (ob->query("family/family_name") == "����Ľ��") {
				level1 = ob->query_skill("xingyi-zhang", 1);
				level2 = ob->query_skill("canhe-zhi", 1);
				if (!level1 && !level2) skill = "���ӳ���";
				else if (level1 > level2) skill = SKILL_D("xingyi-zhang")->query_skill_name(random(level1));
				else skill = SKILL_D("canhe-zhi")->query_skill_name(random(level2));
				message_vision("$N�򴬼Ҵ��˸�Ҿ��������λ���ң�����Ľ�ݵ��ӣ���ȥ" + paizi[i]["name"] + "����\n",ob);
				message_vision("���ҿ��˿�$N��¶�����ɵ���ɫ��\n",ob);
				message_vision("$N��¶΢Ц��ʹ��һ�С�" + skill + "������������Σ���\n���ҵ��˵�ͷ����������������\n",ob);
				ob->start_busy(1);
				call_out("do_move", 1, ob, i);
			}
			else {
				switch (MONEY_D->player_pay(ob, paizi[i]["value"])) {
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


// cunzhang.c

inherit NPC;
int zao(string msg);
int xiu(string msg);
int chai();

void create()
{
	set_name("�һ��峤", ({ "cun zhang", "zhang" }));
	set("gender", "����");
	set("age", random(10) + 40);
	set("str", 25);
	set("dex", 16);
	set("per", 20);
	set("long", "�����һ��峤��˭�����һ������ݰ��ң���Ҫ���������˼ҵ�
ͬ�⡣���Ǹ���Ŀ���Ƶ��Ϻ����ܵ�ȫ���˵����ء�\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);
	set("inquiry", ([
		"����" : "���ݾ��� (zao ���� ����˵��) �Ϳ����ˡ�\n",
		"����" : "��������ӳ��費�����ˣ�(xiu ������ ����������) �ͻ�����װ���ˡ�\n",
		"����" : "����Ҫ�����˻�Կ�׶��˾�(chai)�ɡ�\n",
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob=this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("zao","zao");
	add_action("xiu","xiu");
	add_action("chai","chai");
}

void greeting(object ob)
{
	if (ob->query("age")>17)
say ("�峤Ц�����˵����λ"+RANK_D->query_respect(ob) + "����ӭ���һ�������
���������(zao)��Ҳ�����޸������װ��(xiu)���������Կ��
�͵ò������(chai)�ˡ�����װ�޸û��еĵط����� $ ���档\n");
        else
say ("�峤Ц�����˵����λ"+RANK_D->query_respect(ob) + "�����������������Լ��ķ����ء�\n");
        return;
}

int zao(string msg)
{
	object obj, ob = this_player();
	string homename, homedesc, tmpdesc;

	if (ob->query("age")<17)
	{
		write("\n�峤˵�����㻹û�����أ�������˽լ�ġ�\n");
		return 1;
	}
	if (ob->query("home") )
	{
		write("\n�峤˵���������Ѿ������з����ˣ����������ˡ�\n");
		return 1;
	}
	if( !msg ) return notify_fail("��Ҫ��ʲô������\n");
	if( sscanf(msg ,"%s %s" ,homename, tmpdesc) != 2)
		 return notify_fail("zao ���� ���г���˵��\n");
	homedesc = replace_string(tmpdesc, "$", "\n");
	ob -> set("home/home_name", homename);
	ob -> set("home/home_desc", homedesc);
	ob -> save();
	obj = new("/clone/misc/key");
	obj -> move(ob);
	write("\n�峤˵��������������ȥ�һ�ƺ�������ݣ�����Կ�ף���
�˳���Ϸ�����������Ϳ���ȥ�����ˡ�\n");
	return 1;
}

int xiu(string msg)
{
//        object obj, ob = this_player();
        object ob = this_player();
	string homename, homedesc, tmpdesc;

	if (!ob->query("home") )
	{
		write("\n�峤˵�������ڱ������û�з����ˣ���ʲô�ޣ�\n");
		return 1;
	}
	if( !msg ) return notify_fail("��Ҫ��ʲô������\n");
	if( sscanf(msg ,"%s %s" ,homename, tmpdesc) != 2)
		 return notify_fail("xiu ������ ���г������˵��\n");
	homedesc = replace_string(tmpdesc, "$", "\n");
	ob -> set("home/home_name", homename);
	ob -> set("home/home_desc", homedesc);
	ob -> save();
	write("\n�峤˵��������������ȥ�һ�ƺ�����װ���ݣ������ϾͿ���ȥ�����ˡ�\n");
	return 1;
}

int chai()
{
	object ob = this_player();
	ob->delete("home");
	write("\n�峤˵�����ðɣ�������ķ������Ѿ�����ȥ���ˡ�\n");
	return 1;
}

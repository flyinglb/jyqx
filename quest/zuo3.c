inherit NPC;

int time_period(int timep, object me);
string join_me(object me);

void create()
{
	set_name("����", ({ "leftkiller" }) );
	set("title", "��ɱ�������ʹ");
	set("long",
		"��ɱ�������ʹ������������ɱ�ַ�������\n");

	set("gender", "����" );
	set("age", 28);

	set("str", 30);
	set("int", 23);
	set("cps", 3000);
	set("cor", 30);

	set("combat_exp", 200000000);
	set("attitude", "heroism");

	set("force", 1000);
	set("max_force", 1000);
	set("max_kee", 10000);
	set("force_factor", 10);

	set("food", 100000000);
	set("water", 100000000);

	set("inquiry", ([
		"join": (: join_me :),
		"��ɱ��": "�����˵, С������������! \n",
	]) );

	set_skill("sword", 120);
	set_skill("unarmed", 100);
	set_skill("six-chaos-sword", 100);
	set_skill("dodge", 150);
	set_skill("pyrobat-steps", 100);
	map_skill("dodge", "pyrobat-steps");
	map_skill("sword", "six-chaos-sword");

	setup();
	carry_object("/obj/weapon/longsword")->wield();
	carry_object("/obj/cloth")->wear();
}

int accept_fight(object me)
{
	command("say С�ӣ��������ɱ��, ��Ҫ���ˣ�");
	return 0;
}

void init()
{
	add_action("give_quest", "quest");
}

string join_me(object me)
{
	if((me->query("quest")))
		return  "��λ" + RANK_D->query_respect(me) + ", ���Ѿ�����ɱ�ŵĵ����ˡ�";
	else
		return "Ŷ...������ɱ�����з��յ�Ӵ...";
}

int give_quest()
{
	mapping quest ;
	object me;
	int j, combatexp, timep, factor, num;
	string tag = "1000000";
	string *levels = ({
		"1000",
		"1500",
		"2000",
		"3000",
		"5000",
		"8000",
		"10000",
		"13000",
		"17000",
		"22000",
		"30000",
		"45000",
		"60000",
		"80000",
		"100000",
		"200000",
//		"350000",
//		"600000",
//		"1000000"
	});
	me = this_player();
	combatexp = (int)(me->query("combat_exp"));

	if(combatexp < 1000)
	{
		message_vision("������$N����һ����: ����С��ɫ�������ɱ��, ��Ҳ�����˼����....\n", me);
		return 1;
	}
 
// Let's see if this player still carries an un-expired task
	if((quest =  me->query("quest")))
	{
		if( ((int)me->query("task_time")) >  time() )
			return 0;
		else
		{
			message_vision("������$N����һ����: �����ɱ�Ŷ���, ���ٸ���һ�λ������ԡ�\n", me);
			me->set("kee", (int)(me->query("kee")/2+10));
		}
	}

	for(j = sizeof(levels) - 1 ; j >= 0; j--)
	{
		if( atoi(levels[j])  <= combatexp )
		{
			num = j;
			factor = 10;
			break;
		}
	}
	if(num > 0)
	{
		if (random(50) > 45)
		{
			num = num - 1;
		}
	}
	else
	{
		if ((num < sizeof(levels) - 1) && (random(100) > 95))
		{
			num = num + 1;
			factor = 15;
		}
	}
	tag = levels[num];
	quest = QUEST_D(tag)->query_quest();
	timep = quest["time"];

	while(quest["quest_type"] == "Ѱ")
	{
		quest = QUEST_D(tag)->query_quest();
		timep = quest["time"];
	}

	time_period(timep, me);
	tell_object(me, "ɱ�ˡ�" + quest["quest"] + "��Ϊ��ɱ��������\n" NOR);
	quest["exp_bonus"] = quest["exp_bonus"];
	quest["pot_bonus"] = quest["pot_bonus"];
	quest["score"] = quest["score"];

	me->set("quest", quest);
	me->set("task_time", (int)time() + (int)quest["time"]);
	me->set("quest_factor", factor);
	return 1;
}

int time_period(int timep, object me)
{
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;             t /= 60;
	m = t % 60;             t /= 60;
	h = t % 24;             t /= 24;
	d = t;

	if(d)
		time = chinese_number(d) + "��";
	else
		time = "";

	if(h)
		time += chinese_number(h) + "Сʱ";
	if(m)
		time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";

	tell_object(me, HIW "����˵����\n��" + time + "��");
		return 1;
}
                                                          qlist1000.c                                                                                         100750    1750     144        10407  6604475404  11115  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist1000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            4,
                "pot_bonus":            2,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            4,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "��Ʀ",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 380,
                "exp_bonus":            15,
                "pot_bonus":            7,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "������Ů",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "�ο�",
                "quest_type":           "ɱ",
                "time":                 450,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "��å",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "�廨��",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "�廨��",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "ʢƤ�޿���",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "̨��ũ��",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
                                                                                                                                                                                                                                                         qlist10000.c                                                                                        100750    1750     144        26240  6604476205  11177  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist10000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "ذ��",
                "quest_type":           "Ѱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "ɮ��",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "������ɮ",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "֪��ɮ",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "���⴮",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�в�ɮ",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               15
        ]),
        ([      "quest":                "Կ��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "�ʷ�",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ѻ",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            50,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "���⴮",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            50,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����ɢ",
                "quest_type":           "Ѱ",
                "time":                 900,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��Ƥ",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ͭ��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��Ӣ",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               7
        ]),
        ([      "quest":                "ͭ��",
                "quest_type":           "Ѱ",
                "time":                 400,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            50,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ͷ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ƽ֮",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�в�ɮ",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�಼ɮ��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�η�����",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "֣��ͷ",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "Τ����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            60,
                "pot_bonus":            25,
                "score" :               5
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

                                                                                                                                                                                                                                                                                                                                                                qlist100000.c                                                                                       100750    1750     144        52330  6604471540  11253  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist100000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "���ͷ",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            100,
                "pot_bonus":            15,
                "score" :               150   //over
        ]),
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 780,
                "exp_bonus":            170,
                "pot_bonus":            35,
                "score" :               150   //over
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "exp_bonus":            80,
                "pot_bonus":            15,
                "score" :               50   //over
        ]),
        ([      "quest":                "ϸ����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            100,
                "pot_bonus":            35,
                "score" :               50   //over
        ]),
        ([      "quest":                "��Ա��",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            150,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               20
        ]),
        ([      "quest":                "��ü��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            180,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ݺݺ",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��Ѷ",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            150,
                "pot_bonus":            25,
                "score" :               5
        ]),
        ([      "quest":                "�տն�",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            100,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�䵶",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ɨ��ɮ",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�͵�ŵ",
                "quest_type":           "ɱ",
                "time":                 520,
                "exp_bonus":            120,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 520,
                "exp_bonus":            120,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ʩ����",
                "quest_type":           "ɱ",
                "time":                 520,
                "exp_bonus":            120,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�߸���",
                "quest_type":           "ɱ",
                "time":                 520,
                "exp_bonus":            120,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����ɺ",
                "quest_type":           "ɱ",
                "time":                 520,
                "exp_bonus":            120,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��Ī��",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "÷��",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ѻ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            5,
                "score" :               5
        ]),
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            220,
                "pot_bonus":            35,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            160,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "���",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            80,
                "pot_bonus":            25,
                "score" :               5
        ]),
        ([      "quest":                "���ű���",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            120,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            29,
                "score" :               5
        ]),
        ([      "quest":                "��ȫ",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            180,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "���۷�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            60,
                "pot_bonus":            18,
                "score" :               5
        ]),
        ([      "quest":                "ժ����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ʨ����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�ɻ���",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�޸�����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�ŵ���",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ѩͤ",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "½����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ͷ��",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ͷ��",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ʷ�Ǵ�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���ƽ",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�ٰٳ�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�Ǻ�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�ﲮ��",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "½����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���˷�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ˮ�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ʤ��",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ȭ���ܾ�",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�Ʒ�����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��Ů����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ɽ����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��Ȫ��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ʥ����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�Ҷ�",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            10,
                "score" :               15
        ]),
        ([      "quest":                "�������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            80,
                "pot_bonus":            27,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            7,
                "score" :               5
        ]),
        ([      "quest":                "���峬",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

                                                                                                                                                                                                                                                                                                        qlist13000.c                                                                                        100750    1750     144        26251  6604474515  11206  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist13000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "ذ��",
                "quest_type":           "Ѱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 60,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 50,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "ɮ��",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "������ɮ",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "֪��ɮ",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "���⴮",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�в�ɮ",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               15
        ]),
        ([      "quest":                "Կ��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "�ʷ�",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ѻ",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "���⴮",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����ɢ",
                "quest_type":           "Ѱ",
                "time":                 900,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��Ƥ",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 900,
                "exp_bonus":            120,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "֪�͵���",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ͭ��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               7
        ]),
        ([      "quest":                "ͭ��",
                "quest_type":           "Ѱ",
                "time":                 400,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            50,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ͷ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ƽ֮",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�в�ɮ",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�಼ɮ��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�η�����",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "�彣��",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            60,
                "pot_bonus":            25,
                "score" :               5
        ]),
        ([      "quest":                "Τ����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            60,
                "pot_bonus":            25,
                "score" :               5
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

                                                                                                                                                                                                                                                                                                                                                       qlist1500.c                                                                                         100750    1750     144         5577  6604476253  11121  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist1500.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            4,
                "pot_bonus":            2,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            4,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "��Ʀ",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 380,
                "exp_bonus":            15,
                "pot_bonus":            7,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "������Ů",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "�ο�",
                "quest_type":           "ɱ",
                "time":                 450,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "��å",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "�廨��",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
                                                                                                                                 qlist17000.c                                                                                        100750    1750     144        26671  6604477215  11220  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist17000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "ذ��",
                "quest_type":           "Ѱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "ƽһָ",
                "quest_type":           "ɱ",
                "time":                 60,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 50,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "ɮ��",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "������ɮ",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "֪��ɮ",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "���⴮",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�в�ɮ",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "ʷ��",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               15
        ]),
        ([      "quest":                "Կ��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "�ʷ�",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ѻ",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "���⴮",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����ɢ",
                "quest_type":           "Ѱ",
                "time":                 900,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��Ƥ",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            200,
                "pot_bonus":            40,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ͭ��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��Ӣ",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               7
        ]),
        ([      "quest":                "ͭ��",
                "quest_type":           "Ѱ",
                "time":                 400,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            50,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ͷ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ƽ֮",
                "quest_type":          "ɱ",
                "time":                 200,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�в�ɮ",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�಼ɮ��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�η�����",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "�߸���",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            60,
                "pot_bonus":            25,
                "score" :               5
        ]),
        ([      "quest":                "�׶�",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            60,
                "pot_bonus":            25,
                "score" :               5
        ]),
        ([      "quest":                "Τ����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            60,
                "pot_bonus":            25,
                "score" :               5
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

                                                                       qlist2000.c                                                                                         100750    1750     144         7761  6604477313  11110  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  //  qlist2000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            4,
                "pot_bonus":            2,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            4,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "ɨ��ɮ",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "��Ʀ",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "������Ů",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "�ο�",
                "quest_type":           "ɱ",
                "time":                 450,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "��å",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "�廨��",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "ʢƤ�޿���",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "̨��ũ��",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
               qlist200000.c                                                                                       100750    1750     144        63661  6624311624  11263  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist200000.c

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "��ü��ʦ",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            200,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            200,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���׷�",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����̩",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            180,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ľ����",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            240,
                "pot_bonus":            40,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            240,
                "pot_bonus":            40,
                "score" :               5
        ]),
        ([      "quest":                "���ʦ̫",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            240,
                "pot_bonus":            40,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            240,
                "pot_bonus":            40,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���ַ���",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            40,
                "score" :               5
        ]),
        ([      "quest":                "��ľ���",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "Ѫ������",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�½���",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
         ]),
        ([      "quest":                "���߹�",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���ַ���",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�Ħ��",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��Ħ����",
                "quest_type":           "ɱ",
                "time":                 1800,
                "exp_bonus":            500,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���ȴ�ʦ",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���Ѵ�ʦ",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������ʦ",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�����ʦ",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ʹ��ʦ",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���ٴ�ʦ",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��Զ��",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����Ϫ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�Ŵ�ɽ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����ͤ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "Ī����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ҩʦ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "÷����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "½�˷�",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��Ĭ��",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���ŵ���",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����Ⱥ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "Ī��",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "³����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����ʦ̫",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����ʦ̫",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����ʦ̫",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "½��",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�ѱ�",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��Ӣ��",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�˰���",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�߿���",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ң",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "лѷ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ΤһЦ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ɽͯ��",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ľ����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�鰲ͨ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��׺�",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��а����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            80,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "����������",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            80,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "�ܵ���",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            80,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "��Ů����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            80,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            80,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "����ʯ",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            80,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "��ħ��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            80,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            80,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "��˹����",
                "quest_type":           "Ѱ",
                "time":                 400,
                "exp_bonus":            250,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ľ���",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            250,
                "pot_bonus":            40,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            200,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ɽ�˲�",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            270,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�ɺ�ҩ",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            270,
                "pot_bonus":            30,
                "score" :               5
        ]),

});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}


                                                                               qlist22000.c                                                                                        100750    1750     144        25640  6604500014  11167  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist22000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ɨ��ɮ",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            60,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "ά����峤��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            10,
                "pot_bonus":            3,
                "score" :               5
        ]),
        ([      "quest":                "���ű���",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            15,
                "score" :               20
        ]),
        ([      "quest":                "���ָ",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            30,
                "pot_bonus":            9,
                "score" :               5
        ]),
        ([      "quest":                "��ƽ֮",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            6,
                "score" :               5
        ]),
        ([      "quest":                "��Ƥ",
                "quest_type":           "Ѱ",
                "time":                 100,
                "exp_bonus":            10,
                "pot_bonus":            5,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            15,
                "pot_bonus":            6,
                "score" :               5
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               5
        ]),
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            10,
                "pot_bonus":            7,
                "score" :               5
        ]),
        ([      "quest":                "��Ա��",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ݺݺ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            50,
                "pot_bonus":            15,
                "score" :               20
        ]),
        ([      "quest":                "�Ҷ�",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            7,
                "score" :               5
        ]),
        ([      "quest":                "�䵶",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ƽ֮",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            40,
                "pot_bonus":            13,
                "score" :               5
        ]),
        ([      "quest":                "������ɮ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "֪��ɮ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "���ܹ�",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����ľ��",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "̫��ʮ����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            17,
                "score" :               15
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            17,
                "score" :               15
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            17,
                "score" :               15
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "��˹����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            16,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "������Ů",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            20,
                "pot_bonus":            8,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 900,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��Ƥ",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            10,
                "pot_bonus":            9,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�����ɹ���",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            8,
                "score" :               5
        ]),
        ([      "quest":                "ͭ��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�������",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����ɢ",
                "quest_type":           "Ѱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               5
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

                                                                                                qlist3000.c                                                                                         100750    1750     144         5603  6604473102  11072  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist3000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            4,
                "pot_bonus":            2,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            4,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "��Ʀ",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 380,
                "exp_bonus":            15,
                "pot_bonus":            7,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "������Ů",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "�ο�",
                "quest_type":           "ɱ",
                "time":                 450,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "��å",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "�廨��",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "̨�Ĺ���",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
                                                                                                                             qlist30000.c                                                                                        100750    1750     144        22412  6604500363  11167  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist30000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ɨ��ɮ",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            60,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "ά����峤��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "���ű���",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            15,
                "score" :               20
        ]),
        ([      "quest":                "��ƽ֮",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            6,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            15,
                "pot_bonus":            6,
                "score" :               5
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               5
        ]),
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            10,
                "pot_bonus":            7,
                "score" :               5
        ]),
        ([      "quest":                "��Ա��",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ݺݺ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            50,
                "pot_bonus":            15,
                "score" :               20
        ]),
        ([      "quest":                "�Ҷ�",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            7,
                "score" :               5
        ]),
        ([      "quest":                "�䵶",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ƽ֮",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            40,
                "pot_bonus":            13,
                "score" :               5
        ]),
        ([      "quest":                "������ɮ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "֪��ɮ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����ľ��",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "̫��ʮ����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            17,
                "score" :               15
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "��˹����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            16,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "������Ů",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            20,
                "pot_bonus":            8,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 900,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�����ɹ���",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            8,
                "score" :               5
        ]),
        ([      "quest":                "ͭ��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ˮ��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�������",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��˹����",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            40,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "����ɢ",
                "quest_type":           "Ѱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               5
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

                                                                                                                                                                                                                                                      qlist45000.c                                                                                        100750    1750     144        26301  6604501072  11174  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist45000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            70,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            90,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ά����峤��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "ʥ����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "���峬",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            60,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "���㻨",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            10,
                "pot_bonus":            3,
                "score" :               5
        ]),
        ([      "quest":                "���ű���",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            15,
                "score" :               20
        ]),
        ([      "quest":                "���ָ",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            30,
                "pot_bonus":            9,
                "score" :               5
        ]),
        ([      "quest":                "��ƽ֮",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            6,
                "score" :               5
        ]),
        ([      "quest":                "��Ƥ",
                "quest_type":           "Ѱ",
                "time":                 100,
                "exp_bonus":            10,
                "pot_bonus":            5,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               5
        ]),
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            10,
                "pot_bonus":            7,
                "score" :               5
        ]),
        ([      "quest":                "��Ա��",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ݺݺ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            50,
                "pot_bonus":            15,
                "score" :               20
        ]),
        ([      "quest":                "�Ҷ�",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            7,
                "score" :               5
        ]),
        ([      "quest":                "�䵶",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ƽ֮",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            40,
                "pot_bonus":            13,
                "score" :               5
        ]),
        ([      "quest":                "������ɮ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "֪��ɮ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "���ܹ�",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����ľ��",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "̫��ʮ����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            17,
                "score" :               15
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "��˹����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            16,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "������Ů",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            20,
                "pot_bonus":            8,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 900,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��Ƥ",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            10,
                "pot_bonus":            9,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�����ɹ���",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            8,
                "score" :               5
        ]),
        ([      "quest":                "ͭ��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "�������",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "��˹����",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            40,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               5
        ]),
        ([      "quest":                "����ɢ",
                "quest_type":           "Ѱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               5
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

                                                                                                                                                                                                                                                                                                                               qlist5000.c                                                                                         100750    1750     144         5577  6604501121  11077  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist5000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            4,
                "pot_bonus":            2,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            4,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "��Ʀ",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 380,
                "exp_bonus":            15,
                "pot_bonus":            7,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "������Ů",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "�ο�",
                "quest_type":           "ɱ",
                "time":                 450,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "��å",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "�廨��",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
                                                                                                                                 qlist60000.c                                                                                        100750    1750     144        24221  6604501507  11173  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist60000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "���ͷ",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            100,
                "pot_bonus":            15,
                "score" :               150   //over
        ]),
        ([      "quest":                "�͵�ŵ",
                "quest_type":           "ɱ",
                "time":                 580,
                "exp_bonus":            150,
                "pot_bonus":            25,
                "score" :               150   //over
        ]),
        ([      "quest":                "��˼��",
                "quest_type":           "ɱ",
                "time":                 780,
                "exp_bonus":            200,
                "pot_bonus":            45,
                "score" :               150   //over
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "exp_bonus":            80,
                "pot_bonus":            15,
                "score" :               50   //over
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 700,
                "exp_bonus":            100,
                "pot_bonus":            25,
                "score" :               50   //over
        ]),
        ([      "quest":                "��Ա��",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            150,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            300,
                "pot_bonus":            30,
                "score" :               20
        ]),
        ([      "quest":                "��ü��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            180,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ݺݺ",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��Ѷ",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            150,
                "pot_bonus":            25,
                "score" :               5
        ]),
        ([      "quest":                "�տն�",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            100,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�䵶",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ɨ��ɮ",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�ܼ�",
                "quest_type":           "ɱ",
                "time":                 320,
                "exp_bonus":            120,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��Ī��",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "÷��",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ѻ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            5,
                "score" :               5
        ]),
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            220,
                "pot_bonus":            35,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            160,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "���",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            80,
                "pot_bonus":            25,
                "score" :               5
        ]),
        ([      "quest":                "���ű���",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            120,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�쵤��",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            29,
                "score" :               5
        ]),
        ([      "quest":                "��ȫ",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            180,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "���۷�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�պ������",
                "quest_type":           "Ѱ",
                "time":                 400,
                "exp_bonus":            200,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            5,
                "score" :               5
        ]),
        ([      "quest":                "���⴮",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            20,
                "pot_bonus":            9,
                "score" :               5
        ]),
        ([      "quest":                "�ο�",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            8,
                "score" :               5
        ]),
        ([      "quest":                "ժ����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            290,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               5
        ]),
        ([      "quest":                "�Ҷ�",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            10,
                "score" :               15
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            7,
                "score" :               5
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

                                                                                                                                                                                                                                                                                                                                                                               qlist8000.c                                                                                         100750    1750     144        11507  6604475327  11132  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist8000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            4,
                "pot_bonus":            2,
                "score" :               20
        ]),
        ([      "quest":                "����ϼ",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "��Ʀ",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "��Ů",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "�����̷�",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "��ũ�����",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "����������",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "������Ů",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "�ο�",
                "quest_type":           "ɱ",
                "time":                 450,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 450,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "��å",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "�廨��",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "������ʿ",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "������ʿ",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
                                                                                                                                                                                         qlist80000.c                                                                                        100750    1750     144        57273  6624311621  11210  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // qlist80000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "���ͷ",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            100,
                "pot_bonus":            15,
                "score" :               150   //over
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "exp_bonus":            80,
                "pot_bonus":            15,
                "score" :               50   //over
        ]),
        ([      "quest":                "��Ա��",
                "quest_type":           "ɱ",
                "time":                 800,
                "exp_bonus":            150,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            200,
                "pot_bonus":            30,
                "score" :               20
        ]),
        ([      "quest":                "���ײ�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            300,
                "pot_bonus":            40,
                "score" :               20
        ]),
        ([      "quest":                "��ü��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            180,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ݺݺ",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��Ѷ",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            150,
                "pot_bonus":            25,
                "score" :               5
        ]),
        ([      "quest":                "�տն�",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            100,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�䵶",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ɨ��ɮ",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�͵�ŵ",
                "quest_type":           "ɱ",
                "time":                 520,
                "exp_bonus":            120,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��Ī��",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "÷��",
                "quest_type":           "ɱ",
                "time":                 620,
                "exp_bonus":            220,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ѻ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            5,
                "score" :               5
        ]),
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            220,
                "pot_bonus":            35,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            160,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "���",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            80,
                "pot_bonus":            25,
                "score" :               5
        ]),
        ([      "quest":                "���ű���",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            120,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ȫ",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            180,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "���۷�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            100,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�ο�",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            8,
                "score" :               5
        ]),
        ([      "quest":                "ժ����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               5
        ]),
        ([      "quest":                "�Ҷ�",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            10,
                "score" :               15
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            7,
                "score" :               5
        ]),
        ([      "quest":                "���峬",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            90,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "³�н�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            230,
                "pot_bonus":            28,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            230,
                "pot_bonus":            28,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            230,
                "pot_bonus":            28,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            230,
                "pot_bonus":            28,
                "score" :               5
        ]),
        ([      "quest":                "��Ĭ��",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            230,
                "pot_bonus":            28,
                "score" :               5
        ]),
        ([      "quest":                "½�˷�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            230,
                "pot_bonus":            28,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 520,
                "exp_bonus":            120,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ʩ����",
                "quest_type":           "ɱ",
                "time":                 520,
                "exp_bonus":            120,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�߸���",
                "quest_type":           "ɱ",
                "time":                 520,
                "exp_bonus":            120,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����ɺ",
                "quest_type":           "ɱ",
                "time":                 520,
                "exp_bonus":            120,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            60,
                "pot_bonus":            18,
                "score" :               5
        ]),
        ([      "quest":                "ժ����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ʨ����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�ɻ���",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�޸�����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�ŵ���",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ѩͤ",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "½����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ͷ��",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��ͷ��",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ʷ�Ǵ�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���ƽ",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�ٰٳ�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�Ǻ�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "�ﲮ��",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "½����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "���˷�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ˮ�",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "ʤ��",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "exp_bonus":            190,
                "pot_bonus":            30,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ȭ���ܾ�",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�Ʒ�����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��Ů����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��ɽ����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "ʥ����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "exp_bonus":            200,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "�Ҷ�",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            10,
                "score" :               15
        ]),
        ([      "quest":                "�������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            80,
                "pot_bonus":            27,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            7,
                "score" :               5
        ]),
        ([      "quest":                "���峬",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

                                                                                                                                                                                                                                                                                                                                     quest.c                                                                                             100750    1750     144         2342  6601453635  10577  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  #include <ansi.h>

inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object me, string arg)
{
        int nowtime = time();
        mapping quest;
        if(!(quest =  me->query("quest")))
               return notify_fail("������û���κ�����\n");
        write("�����ڵ�������" + quest["quest_type"] + "��" + quest["quest"] + "����\n");
        nowtime = (int) me->query("task_time") - time();
        if( nowtime  > 0 )
                time_period(nowtime, me);
        else
                write("�������Ѿ�û���㹻��ʱ����������ˡ�\n");

        return 1;
}
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        tell_object(me,"�㻹��" + time + "ȥ�������\n");
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : quest  ���ָ�������ʾ���㵱ǰ������
HELP
        );
        return 1;
}
                                                                                                                                                                                                                                                                                              you4.c                                                                                              100750    1750     144        16130  6601454554  10357  0                                                                                                    ustar   mud                             users                                                                                                                                                                                                                  // right_killer.c
// modified by wind

#include <ansi.h>
inherit NPC;
int time_period(int timep,object me);

void create()
{
        set("chat_chance", 25);

        set_name("����", ({ "right" }) );
        set("title", "��ɱ���ҽ���ʹ");
        set("gender", "Ů��" );
        set("age", 28);
        set("str", 30);
        set("int", 24);
        set("cps",30);
        set("long",
                "��ɱ���ҽ���ʹ����нӰ�ɱ�����⡣\n");
        set("combat_exp", 2000000);
        set("attitude", "heroism");

        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 10);

        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("whip", 120);
        map_skill("whip", "snowwhip");

       set("inquiry", ([  "��ɱ��": "�����˵, С�Ĺ�����������! \n",
        ]) );

        setup();
}
int accept_fight(object me)
{
        command("say С�ӣ��������ɱ��, ��Ҫ���ˣ�");
        return 0;
}

void init()
{
        add_action("give_quest", "quest");
}

int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num;
        string tag = "1000000";
        string *levels = ({
                         "1000",
                        "1500",
                        "2000",
                        "3000",
                        "5000",
                        "8000",
                        "10000",
                        "13000",
                        "17000",
                        "22000",
                        "30000",
                        "45000",
                        "60000",
                        "80000",
                        "100000",
                        "200000"
//                        "350000",
//                        "600000",
//                        "1000000"
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));

        if(combatexp<1000)
          {
        message_vision("���Ķ�$N����һ����: ����С��ɫ��������ɱ��, ��Ҳ�����˼
����....\n",me);
         return 1;
          }

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
        if( ((int) me->query("task_time")) >  time() )
        {
          message_vision("���Ķ�$N���ĵ�һЦ��: ��Ҫ��ɱ�ų���, �����Ȱ����������ɰɡ�\n", me);
                  message_vision("Ȼ����ͷ��������˵������Ҫ�Ǿ����������͵ø���������ˡ�\n",me);
          return 0;
        }
        else
        {
          message_vision("���Ķ���$N̾��һ����:�����Ҿ��ٸ���һ�λ���ɡ�\n", me);
          me->add("qi",-(int)(me->query("qi")/10));
        }
        }

        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                      num=j;
                          factor=10;
                          break;
                        }
        }
        if (num>0)
        {
                if (random(50)>45)
                {
                num=num-1;
                }
        } else {
                if ((num<sizeof(levels)-1)&&(random(100)>95))
                {
                num=num+1;
                factor=15;
                }
        }
        tag=levels[num];
        quest = QUEST_D(tag)->query_quest();
        timep = quest["time"];

 //       while (quest["quest_type"] == "ɱ")
 //       {
 //       quest = QUEST_D(tag)->query_quest();
 //       timep = quest["time"];
 //       }

        time_period(timep, me);
        if(quest["quest_type"]=="ɱ")
        tell_object(me,"������ɱ�ˡ�"+quest["quest"]+"��,�����Ҹ�����ɱ�֡�\n" NOR);
        else
        tell_object(me,"���һء�"+quest["quest"]+"������,�����Ҹ�����ɱ�֡�\n" NOR);
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];

        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,HIW "����˵����\n��" + time + "��");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor;
        string test;
        mapping quest;

                if (ob->query("money_id"))
                {
                        if(!who->query("quest"))
                        {
              message_vision("����Ц��: ���ҿɾͲ������ˡ�\n",who);
                          return 1;
                        }
                        if ( ob->value() < 10000)
                        {
                                message_vision("����һ˫�������۾�ֱ����$N:���Ǯ�ɲ������ǵĿ���ѽ!\n", who);
                                return 1;
                        }
                        else
                        {
              message_vision("����Ц��: �Ǻã������������������ڡ����������Ұɣ�\n",who);
                          who->set("quest",0);
                          return 1;
                        }

                }

        if(!(quest =  who->query("quest")))
        {
        tell_object(who,"����˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
        tell_object(who,"����˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"����˵�������ϧ����û����ָ����ʱ���ڻ�����\n");
        destruct(ob);
        return 0;
        }

        else
        {
        tell_object(who,"����˵�����Բ���������ɱ�Ż�������ɱ�֣�\n");
        exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
        pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
        score = quest["score"]/2 + random(quest["score"]/2);
        factor=who->query("quest_factor");
        destruct(ob);

        if (factor)
        {
                exp=exp*factor/10;
                pot=pot*factor/10;
                score=score*factor/10;
        }

        bonus = (int) who->query("combat_exp");
        bonus += exp;
        who->set("combat_exp", bonus);
        bonus = (int) who->query("potential");
        bonus = bonus - (int) who->query("learned_points");
        bonus = bonus + pot;
        if( bonus > 300) bonus = 300;
        bonus += (int) who->query("learned_points");
        who->set("potential", bonus );
        bonus = (int) who->query("score");
        bonus += score;
        who->set("score", bonus);
        tell_object(who,HIW"�㱻������\n" + chinese_number(exp)
          + "��ʵս����\n"+ chinese_number(pot) + "��Ǳ��\n"
          + chinese_number(score)+"���ۺ�����\n"NOR);
        who->set("quest", 0 );
         return notify_fail("��ϲ�����һ������\n");;
        }
     return 1;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        

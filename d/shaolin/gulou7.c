// Room: /d/shaolin/gulou7.c
// Date: YZC 96/01/19

inherit ROOM;

string look_drum();
string look_out();

void create()
{
	set("short", "��¥�߲�");
	set("long", @LONG
������ǹ�¥֮����ֱ�������ı���һֻ��ġ���Ĺ���ͨ�죬
���ɰ���ľ���ɡ���ͷ����ˮţƤ����һ�Ѵ�ͭ�����ڹ����Ե��
������һȦ���գ���������Ϊ��λ����γɵġ�������ķ���һ
��һ�˸ߵļ����ϣ����ӵײ�����������鳡�����ɽ�紵����
����˭������ס���һ�¹�(drum)���ԡ����⿴���и��ܴ�ĺ�
����̨(out)���������վһ���ˡ�
LONG );
	set("exits", ([
		"down" : __DIR__"gulou6",
	]));
	set("item_desc",([
		"drum"		:	(: look_drum :),
		"out"		:	(: look_out :),
	]));
	set("objects",([
		CLASS_D("shaolin") + "/qing-wen" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_hit", "hit");
	add_action("do_out", "out");
}

int do_hit(string arg)
{
	object me;

	me = this_player();
	if ( !arg || ( arg != "drum" ) ) return notify_fail("��Ҫ��ʲ�᣿\n");

	me->add("qi", -30);

	if ( random((int)me->query("kar")) < 5 )
	{
		message_vision("$Nһ��С���õ��Լ�ͷ���ˡ�\n", me);
		//me->add("qi", -10 - me->query("qi"));
		me->unconcious();
	}

	else
	{
		mapping mine;

		mine = me->query_entire_dbase();
		message_vision("$N����һ�´�ģ����ˡ���������������������\n", me);
		write("������Ѹ�װ��������ը�죬��ͷ����һƬ��Ϳ��\n"
			"ȫ��ҡҡ��׹������֧���Ų����ڵ��ϡ�����һ��\n"
			"���������㣬�øϿ��뿪�����Ȼ��û���ˡ�\n");
         if (random(2)==0) 
         {
            if ( mine["potential"] - mine["learned_points"] < 100 )
                 mine["potential"] += 1;
         }
         else
         {
            if ( mine["potential"] - mine["learned_points"] > 0 )
                 mine["potential"] -= 1;
         }
	}
	return 1;
}

int do_out(string arg)
{
        object me;


int i, ging_cost, qi_cost;

        me = this_player();
//        i = (int)me->query_skill("dodge", 0) + random(200);
//    ��ֹrobot, �����busy�ͼ�����������
        me->start_busy(5);
        i = (int)me->query_skill("dodge", 0) + random(5);
        ging_cost = 600 / (int)me->query("int");
        qi_cost = 500 / (int)me->query("int");
        if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
                i = 0;

        message_vision("$N���ϴ�̨��һ������������ȥ��\n", me);
        me->move(__DIR__"gulou");
        message_vision("ֻ�����须��һ��$N����������������\n", me);
        if ( i < 50)
                me->die();
        else if( i < 125)
                me->unconcious();
        else {
                message_vision("$N�����ȵ�վ�ڵ��ϡ�\n", me);
                if( i > 175 && me->query_skill("dodge",1)<200)
                        me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
                me->receive_damage("jing", ging_cost );
                me->receive_damage("qi", qi_cost );
        }

        return 1;
}

string look_drum()
{
	return
	"��������������������������������������������\n"
	"��������������������������������������������\n"
	"������������������������Ի������������������\n"
	"��������������������������������������������\n"
	"��������������һ����������һ�ιġ�����������\n"
	"��������������������������������������������\n"
	"��������������������������������������\n"
	"��������������������������������������������\n"
	"��������������������������������������������\n";
}

string look_out()
{
	return  "�����ǹ�¥����Ĵ�̨�����������ң����������ɽ����\n"
"�Լ��������Ƶ���ɽ�������̳��������۵ס���˵�ڴ˵�\n"
"������������ֱ�ӽ����������޴����洦��\n";
}


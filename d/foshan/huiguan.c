//Room: /d/foshan/huiguan.c
//Date: June. 29 1998 by Java

inherit ROOM;
int sos(int,int);
void fresh(object ob);
void create()
{
	set("short","Ӣ�ۻ��");
	set("long",@LONG
Ӣ�ۻ��Ҳ�Ƿ���ү�ļ�ҵ���������Ǯ�ģ���������������
ͷ�ġ��ĳ���Χ�ź�ѹѹ��һȺ�ˣ�������(gamble)����Ѻ��С��
�ű�����һ������(paizi)��
LONG);
	set("objects", ([
	   __DIR__"npc/fengyiming": 1,
	]));
	set("no_fight", "1");
        set("item_desc", ([
                "paizi" :
"����С���ķ���\n"
"��������ɫ������һֻ���ɫ�ӵ����ܺͣ�\n"
"       �� �� ʮ Ϊ��С����\n"
"       ʮһ �� ʮ�� Ϊ���󡹣�\n"
"       ����ɫ�ӵ�����ͬ�����Сͨ�ԡ�\n"
"\n������󣬿�С��С��һ��һ��\n"
"\n���ĳ����ܸ��ֻ��Ҽ�����ĵ���Ϊ��ע��\n"
"\n��עΪ��ʮ��һǧ��١�\n",
        ]));
	set("exits",([ /* sizeof() == 1 */
	    "north" : __DIR__"street2",
	]));
	setup();
}
void init()
{
        add_action("do_gamble", "gamble");
}

int do_gamble(string arg)
{
        int a,b,c;
        int wager, skill, lpoint, tpoint;
        string wtype1, wtype2, wtype0, status;
        object mtype, me;
        mapping lrn;

        int min, max;
        min = 50;
        max = 1500;

        me = this_player();

        if (me->query_temp("casino/mark"))
                return notify_fail("����ô�ż���? �����ٶ���Ϣһ����� -:)\n");

    if (!arg || sscanf(arg, "%s %s %s %d", wtype0, wtype1, wtype2, wager) !=4)
        return notify_fail("gamble big|small money|skill <type> <amount>\n"
"eg. gamble big money silver 3 OR gamble small skill dodge 10\n");

        if (wtype1 == "money")
        {
                mtype = present(wtype2 + "_money", me);
                if( !mtype)          return notify_fail("������û�����ֻ��ҡ�\n");
                if( wager < 1 )        return notify_fail("��Ҫѹ���ٰ�?\n");
                if( (int)mtype->query_amount() < wager)
                        return notify_fail("������û����ô��" + mtype->query("name") + "��\n");
                if( wager*(mtype->query("base_value")) < min ||
                    wager*(mtype->query("base_value")) > max )
                        return notify_fail("��Ķ�ע�����޶�֮��!\n"
                        "������޶���" + chinese_number(min) + "��" + chinese_number(max) + "��\n");
        }
        else if (wtype1 == "skill")
        {
                skill = me->query_skill(wtype2, 1);
                if( skill < 1 )
                return notify_fail("��Ҫթ�İ�? ��������������!\n");
                lrn = me->query_learned(wtype2, 1);
                lpoint = (int)lrn[wtype2];
//              message_vision("learned pt: " + lpoint + "\n", me);
                tpoint = lpoint + sos(1, skill);
//              message_vision("total learned pt: " + tpoint + "\n", me);
                if (wager > tpoint) return notify_fail("��Ĳ���!\n");
                if (wager < min || wager > max)
                        return notify_fail("��Ķ�ע�����޶�֮��!\n"
                        "������޶���" + chinese_number(min) + "��" + chinese_number(max) + "��\n");
        }
        else    return notify_fail("���ĳ����������ֶ�ע��\n");

        if ( (wtype0 != "big") && (wtype0 != "small") )
                return notify_fail("��Ҫ�Ĵ��Ƕ�С?\n");

        me->set_temp("gamb_t",(me->query_temp("gamb_t") +1));
        if (me->query_temp("gamb_t") > 50)
        {
                call_out("fresh", 300, me);
                me->set_temp("casino/mark", 1);
                return notify_fail(
"��λ" + RANK_D->query_respect(me) + "�����Ѿ����˺ܾ��ˣ���������Ϣһ����ɡ�\n");
        }

        a = random(6) + 1;
        b = random(6) + 1;
        c = random(6) + 1;

        message_vision("����" + a + "   " + b + "   " + c + "   ��", me);

        if ((a == b) && (b == c) )
//              message_vision("����" + a + " " + b + " " + c " ,��Сͨɱ��\n", me);
                message_vision("��Сͨɱ��\n", me);
        else if ( (a+b+c) > 10 )
//              message_vision("����" + a + " " + b + " " + c " ,��С���\n", me);
                message_vision("��С���\n",me);
        else if ( (a+b+c) < 11 )
//              message_vision("����" + a + " " + b + " " + c " ,�Դ���С��\n", me);
                message_vision("�Դ���С��\n",me);

        if ( ( (a == b) && (b == c) ) ||
             ( (a+b+c) > 10 && (wtype0 == "small") ) ||
             ( (a+b+c) < 11 && (wtype0 == "big") ) )
                status = "lose";

        if (wtype1 == "money")
        {
                if ( status == "lose") {
        message_vision(me->query("name") + "����" + chinese_number(wager) +
mtype->query("base_unit") + mtype->query("name") + "��\n", me);
                        mtype->set_amount((int)mtype->query_amount() - wager);
                        mtype->move(me);
                }
                else {
        message_vision(me->query("name") + "Ӯ��" + chinese_number(wager) +
mtype->query("base_unit") + mtype->query("name") + "��\n", me);
                        mtype->set_amount((int)mtype->query_amount() + wager);
                        mtype->move(me);
                }
        }
        else if (wtype1 == "skill")
        {
                if ( status == "lose") {
        message_vision(me->query("name") + "����" + chinese_number(wager) +
"��" + to_chinese(wtype2) + "�Ĺ�����\n", me);
                        wager -= lpoint;
                        while (wager > 0)
                        {
                           wager -= skill*skill;
                           skill -= 1;
                        }
                        wager *= -1;
                        if (wager > lpoint) wager -= lpoint;
                        else wager += (lpoint*-1);
                }
                else {
        message_vision(me->query("name") + "Ӯ��" + chinese_number(wager) +
"��" + to_chinese(wtype2) + "�Ĺ�����\n", me);
                        wager += lpoint;
                        while (wager >= (skill+1)*(skill+1))
                        {
                          skill += 1;
                          wager -= skill*skill;
                        }
                        wager -= lpoint;
                }
                me->set_skill(wtype2, skill);
                me->improve_skill(wtype2, wager);
        }
        return 1;
}

void fresh(object ob)
{
        ob->delete_temp("gamb_t");
        ob->delete_temp("casino/mark");
}

int sos(int lower, int upper)
{
        int x,y;
        x = 0;

        while (lower <= upper)
        {
                y = lower*lower;
                x += y;
                lower++;
        }
        return x;
}
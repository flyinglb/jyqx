inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����Ʈѩɽׯ��̳�Ĵ��������ܸ����ûʣ����㿴�����ۣ������������
�Ѵ��Ρ��������������Ʈѩɽׯׯ��������λ�ã��ұ��Ǹ�ׯ������Ȼ�ġ�
���εĺ�����һ��ͼ����������Ʈѩɽׯ��ǰ����λׯ������������������
����һ��������duilian)��
LONG );
        set("valid_startroom",1);
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1");
        set("item_desc",([
                "duilian" : "�����ɵ���ƮѪ�����츣��������\n",
        ]));
        set("exits", ([
                "east"  : __DIR__"shenlong",
                "west"  : __DIR__"piaoxie",
                "out"   : "/d/city/guangchang",
        ]));
        setup();
        "/clone/board/piaoxue_b"->foo();
        }

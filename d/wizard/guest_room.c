// /d/wizard/guest_room.c
// modified by wind

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʦ�����");
	set("long", @LONG
��������ʦ����ҽ����ĵط����������ʲô������Ҫ����ʦ��
�̣���������������(post)�������������ǣ�浽���ջ����Ѿ��ڰ�
���ļ�������ϸ˵������ʦ�ǾͲ�һ����ش�¥������ʦ��Ϣ�ң�
һ����ҵ��������ϲ�ȥ�ˡ�
LONG
	);

	set("exits", ([
		"up": __DIR__"wizard_room",
		"southeast": "/d/city/wumiao" ]));
	set("no_fight", 1);
//	set("no_get", "1");
	create_door("southeast", "����", "northwest", DOOR_CLOSED);

	setup();
	call_other("/clone/board/towiz_b", "???");
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
		return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}

void init()
{
      object tingyu_room=find_object("/d/city2/tingyu");
       if (!userp(this_player())) return;
      if (!objectp(tingyu_room))
          tingyu_room=load_object("/d/city2/tingyu");
         add_action("do_dazuo", "dazuo");
        add_action("do_tuna", "tuna");
        add_action("do_sleep", "sleep");
}
 int do_dazuo(string arg)
{
        write("���������޷�����������\n");
        return 1;
}
int do_tuna(string arg)
{
        write("���������޷�����������\n");
        return 1;
}
int do_sleep(string arg)
{
        write("����������ôҲ˯���š�\n");
        return 1;
}

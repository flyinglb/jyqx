// by mayue

inherit ROOM;

void create()
{
	set("short", "�һ���");
	set("long", @LONG
��������ɽ��е�Ͽ���У�ɽ��ɽ��ȫ���ޱߵ�Ұ������һ��
ɽ�紵������Ӣ�ͷס����������µ��һ�����֦���ѻ��ڵ��ϣ���
������������ġ��ս������ˣ�Զ��ɽ�ּ��ƺ�Ʈ����һ������
Խ��ԽŨ��
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"wdsl1",
//		"southeast" : __DIR__"taohua",
//		"west" : __DIR__"wumiao",
		"northwest" : __DIR__"xiao3",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
//	replace_program(ROOM);
}
int valid_leave (object who, string dir)
{
  if(dir=="northwest"){
//      who->move("d/wudujiao/xiao3");
//     return 1;
     return ::valid_leave(who, dir);
    }
else{
if ((string)who->query("family/family_name")!="�嶾��")
   {
    if(!(present("xingjun san", who))){
      message_vision ("һ��Ũ��Ϯ����$N��ʱ����ͷ�ؽ��ᡣ\n",who);
      who->receive_damage("qi", 50);
      remove_call_out ("fall_down");
      call_out ("fall_down",1,who,environment(who));
      who->start_busy(1,1);
      return notify_fail("�����ס�����˼��£�����ͻȻһ��\n");
//    who->unconcious();
     } 
   }
  return 1;
    }
}

void fall_down (object who, object where)
{
  who->move(where);
  this_player()->unconcious();
}
void fall_down1 (object who, object where)
{
  this_player()->unconcious();
}


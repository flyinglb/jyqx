#include <ansi.h>

inherit ROOM;

void rtaohua( object ob ) ;

void create()
{
    set("short", "��̲");
    set("long", @LONG
�����һ���ǰ�ĺ�̲��������һ���޼ʵĴ󺣣���������һƬ�һ��֡�
�����ĺ��������죬���ɫ��ɳ̲���ۺ���һ�����һ�ж�����ô��������
����һ�Ҵ�(chuan)��
LONG );
    set("item_desc", ([
        "chuan" : "�����һ���������ϵ�Ĵ󴬡����ϵĿ��˻����ֻҪ\n"
                  "�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
    ]));
    set("exits",([
        "south" :__DIR__"tao_in",
	"east"  :__DIR__"jiaoshi",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "taohua");
    setup();
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("�������𷫣��������������С�\n", ob);
    ob ->move("/d/taohua/dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("rtaohua", 10 , ob );
    return 1 ;
}
void rtaohua( object ob )
{
  tell_object(ob , "�����ڵִ�����ԭ��һ���������С������´�����\n" ) ;
  ob->move ("/d/quanzhou/jiaxinggang") ;
}

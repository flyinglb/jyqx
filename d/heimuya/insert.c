//insert.c
#pragma optimize
#include <dbase.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping cards;
	string *dirs, dir;
	int i;

	if( !arg ) return notify_fail("��Ҫ����ʲô��\n");

	cards = environment(me)->query_cards();
	if( mapp(cards) ) {
		dirs = keys(cards);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==cards[dirs[i]]["name"] || member_array(arg, cards[dirs[i]]["id"])!=-1 ) {
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("��Ҫ����ʲô��\n");
	
		if( environment(me)->insert_card1(dir) ) {
			message_vision("$N��" + cards[dir]["name"] + "���롣\n", me);
			return 1;
		}
	}

	return 0;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : open <door> �� <����>
 
���ָ������������.
 
HELP
    );
    return 1;
}

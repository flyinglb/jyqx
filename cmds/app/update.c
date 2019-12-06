// update.c
// by atu for SJFY

#include "/doc/help.h"
#include <runtime_config.h>
inherit F_CLEAN_UP;

int update_player(object me);

int main(object me, string file)
{
	int i;
	object obj, *inv;
	string err;

	seteuid( geteuid(me) );

	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("��Ҫ���±���ʲô������\n");

	if( (obj = present(file, environment(me))) && interactive(obj) )
		return update_player(obj);

	if( file == "me" )
		return update_player(me);
	else {
		file = resolve_path(me->query("cwd"), file);
		if( !sscanf(file, "%*s.c") ) file += ".c"; 
	}

	if( file_size(file) < 0 )
		return notify_fail("û�����������\n");

	me->set("cwf", file);

	if (obj = find_object(file)) {
                if( file_name(obj)==VOID_OB && file_name(environment(me)) == VOID_OB )
			return notify_fail("�㲻���� VOID_OB �����±��� VOID_OB��\n");
		inv = all_inventory(obj);
		i = sizeof(inv);
		while(i--)
			if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
			else inv[i] = 0;
		err = get_config(__SAVE_BINARIES_DIR__) + file[0..<3]+".b";
		write("ɾ���������ļ� "+err+" ...");
		if( file_size(err) < 0 ) write("�����ڡ�\n");
		else if (rm(err)) write("�ɹ���\n");
		else write("ʧ�ܡ�\n");

		destruct(obj);
	}

	if (obj) return notify_fail("�޷�����ɳ�ʽ�롣\n");

	write("���±��� " + file + " ...");
	err = catch( call_other(file, "???") );
	if (err)
		printf( "��������\n%s\n", err );
	else {
		write("�ɹ���\n");
		if( (i=sizeof(inv)) && (obj = find_object(file))) {
			while(i--)
				if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
		}
	}

	return 1;
}

int update_player(object me)
{
	object env, link_ob, obj;

	env = environment(me);

	// First, create the new body.
	link_ob = me->query_temp("link_ob");
	obj = LOGIN_D->make_body(link_ob);
	if (!obj) return 0;

	// Save the data and exec the player to his/her link object.
	me->save();
	exec(link_ob, me);
	destruct(me);

	// Restore new body and exec to it via enter_world in LOGIN_D
	obj->restore();
	LOGIN_D->enter_world(link_ob, obj, 1);

	write("���������ϡ�\n\n");
	obj->move(env);
	obj->write_prompt();

	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : update <����|here|me|�����>
 
���ָ����Ը��µ���, �����µ������������������. ��Ŀ��Ϊ
'here' ��������ڻ���. ��Ŀ��Ϊ 'me' ������Լ�������. ��Ŀ
��Ϊ�����ɸ���������.
 
HELP );
    return 1;
}

// promote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string old_status, new_status;

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
		return notify_fail("ָ���ʽ��promote <ʹ����> <�ȼ�>\n");

	if( wiz_level(new_status) < 0 ) return notify_fail("û�����ֵȼ���\n");

	if( !objectp(ob = present(arg, environment(me))) 
	||	!userp(ob) )
		return notify_fail("��ֻ�ܸı�ʹ���ߵ�Ȩ�ޡ�\n");
		
	if( wiz_level(me) < wiz_level(new_status) )
		return notify_fail("��û������Ȩ����\n");

	old_status = wizhood(ob);

	seteuid(getuid());
	if( !(SECURITY_D->set_status(ob, new_status)) )
		return notify_fail("�޸�ʧ�ܡ�\n");

	message_vision("$N��$n��Ȩ�޴� " + old_status + " ��Ϊ " + new_status + " ��\n", me, ob);
	
        seteuid(getuid());
        ob = present(arg, environment(me));//����ָ�����
        ob->setup();

        if(ob->query("read_wizfiles") != 1){
                ob->set("read_wizfiles",1);
                ob->start_more( read_file("/doc/wiz/new_wiz") );
        }
	if(new_status == "(player)")
	        ob->delete("read_wizfiles");
	        
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : promote <ĳ��> (Ȩ�޵ȼ�)

��������Ȩ�޵ȼ�, (player) (immortal) (apprentice) (wizard)
(arch) (admin)
һ�� admin ������Ȩ�����κεȼ�, �� arch ֻ�������� arch��
HELP
    );
    return 1;
}

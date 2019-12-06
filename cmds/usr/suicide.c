// suicide.c
// modified by wind

#include <ansi.h>
// inherit F_CLEAN_UP;
int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("����һ��������û��ɡ�\n");
	if( !arg ) {
		write("��ɱ�����Ҫ�����Ӵ��\n");
		return 1;
	}
	if( arg!="-f" ) 
                return notify_fail("��ɱ�����Ҫ�����Ӵ��(help suicide)\n");
	if (SECURITY_D->get_status(me)!="(player)")
		return notify_fail("�����Ҫ��������ʦ���㽵����Ҳ�����ɱ!\n");
        if ((int)me->query("mud_age")<900)
		return notify_fail("���ذɣ���ô���������ɱ��\n");
	write(
		"�����ѡ����Զ��������ɱ��ʽ�������������Ͼ���Զɾ���ˣ������\n"
		"���������ȷ���Ļ��������������룺");
	input_to("check_password", 1, me, 1);
	return 1;
}
protected void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;
	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("�������\n");
		return;
	}
	if (forever) {
		tell_object( me,
		HIR "\n\n�����Ҫ��ɱ�ˣ������ʮ���ڲ���ڣ�����������ˡ�\n\n\n" NOR);
                CHANNEL_D->do_channel(this_object(),"rumor",me->name() + "����Ҫ��ɱ�ˡ�");
                tell_room(environment(me),HIY"\n"+me->query("name")
                +HIY"����̾��һ�����ճյ�����Զ���������˼֮��......\n"NOR,({me}));
		me->start_busy(30);
		me->set_temp("suicide",1);
		call_out("slow_suicide",5,me,40);
	}
}
protected int slow_suicide(object me,int sec)
{
	if (!me)	return 0;
	sec-=5;
	if (sec>1){
		tell_object(me, RED "\n\n\n�㻹��"+YEL+chinese_number(sec)+"��"+RED+"��ʱ�������ڡ�\t\t"+HIW+"���������ˣ��������˳�(quit)��Ϸ��\n\n\n" NOR);
		call_out("slow_suicide",5,me,sec);
	}else	call_out("do_suicide",1,me);
	return 1;
}
int do_suicide(object me)
{
        string id,mailfile;
	object link_ob;
	if (!me)	return 0;
	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;
	log_file("static/SUICIDE",
		sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );
        id=me->query("id");
        seteuid(getuid());
	rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
	rm( me->query_save_file() + __SAVE_EXTENSION__ );
        mailfile=sprintf(DATA_DIR "mail/%c/%s", id[0], id);
        rm (mailfile+ __SAVE_EXTENSION__ );
        write(HIY"�ðգ��������ѡ����ɽ���ɣ���ˮ����������......\n\n\n"NOR);
        tell_room(environment(me), HIW"\n\nһ��紵��������ֻ��"HIG +me->name()+ HIW"����ӻ��֣�Ȼ����һ�㵭����......\n\n"
        MAG"�����ȡʲô��ȴ���ʲôҲûץ��......\n\n"NOR, ({me}));
	destruct(me);
	return 0;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: suicide -f
 
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ��
 
suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ����
             ����������ȷ����ݡ�
 
������ѡ�� :)
 
HELP
);
        return 1;
}

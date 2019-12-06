// suicide.c
// modified by wind

#include <ansi.h>
// inherit F_CLEAN_UP;
int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("你上一个动作还没完成。\n");
	if( !arg ) {
		write("自杀？你可要想清楚哟！\n");
		return 1;
	}
	if( arg!="-f" ) 
                return notify_fail("自杀？你可要想清楚哟！(help suicide)\n");
	if (SECURITY_D->get_status(me)!="(player)")
		return notify_fail("你必须要由其他巫师把你降成玩家才能自杀!\n");
        if ((int)me->query("mud_age")<900)
		return notify_fail("保重吧，这么年轻就想自杀？\n");
	write(
		"如果您选择永远死掉的自杀方式，这个人物的资料就永远删除了，请务必\n"
		"考虑清楚，确定的话请输入您的密码：");
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
		write("密码错误！\n");
		return;
	}
	if (forever) {
		tell_object( me,
		HIR "\n\n你决定要自杀了，如果四十秒内不後悔，就真的永别了。\n\n\n" NOR);
                CHANNEL_D->do_channel(this_object(),"rumor",me->name() + "决定要自杀了。");
                tell_room(environment(me),HIY"\n"+me->query("name")
                +HIY"轻轻叹了一声，痴痴地望着远方，陷入沉思之中......\n"NOR,({me}));
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
		tell_object(me, RED "\n\n\n你还有"+YEL+chinese_number(sec)+"秒"+RED+"的时间可以後悔。\t\t"+HIW+"如果你後悔了，请马上退出(quit)游戏。\n\n\n" NOR);
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
        write(HIY"好罢，这是你的选择，青山依旧，绿水长流，别了......\n\n\n"NOR);
        tell_room(environment(me), HIW"\n\n一阵风吹来，隐隐只见"HIG +me->name()+ HIW"对你挥挥手，然后雾一般淡化了......\n\n"
        MAG"你想攫取什么，却终於什么也没抓到......\n\n"NOR, ({me}));
	destruct(me);
	return 0;
}
int help (object me)
{
        write(@HELP
指令格式: suicide -f
 
如果因为某种原因你不想活了, 你可以选择自杀。
 
suicide -f : 永远的除去玩家资料, 系统会要求你
             输入密码以确认身份。
 
请慎重选择 :)
 
HELP
);
        return 1;
}

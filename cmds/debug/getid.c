 // getid.c

inherit F_CLEAN_UP;

#include <ansi.h>

void create()
{
 seteuid(getuid());
}


private int get_sameaddress_players(string adress);

int main(object me, string arg)
{
string status;

 status = wizhood(me);
 if( me!=this_player(1)
 || wiz_level(me) < wiz_level(status) )
 return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
 if(!arg) return notify_fail("ָ���ʽ��getid (player's ip)\n");
        return get_sameaddress_players(arg);
}

private int get_sameaddress_players(string address)
{
        int i, j, ppl_cnt, count;
        string *dir, *ppls, name;
      object ob;
        seteuid(getuid());
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();

                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                for(j=0; j<sizeof(ppls); j++) {
                   if( sscanf(ppls[j], "%s.o", name)==1 ) {

                  ob = new(LOGIN_OB);
                  ob->set("id", name);
                  if (!ob->restore()) {
                destruct(ob);
continue;
 }
 else {
                  if(ob->query("last_from")==address){
                    write("id  :"+ob->query("id")+"\n");
                    write("name:"+ob->query("name")+"\n");
                    count ++;
               }
           destruct(ob);

                 }
             }
   }
}
    if(count)
        write( count + "λʹ���ߡ�\n");
    else
        write("���������ʹ����.\n");
return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��getid adress

find the id of an adres
HELP
        );
    return 1;
}

// combined_item.c
//modified by hero 2000.1.24
#include <dbase.h>
#include <name.h>
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;
nosave int amount;
void setup()
{
}
int query_amount() { return amount; }
protected void destruct_me() { destruct(this_object()); }
void set_amount(int v)
{
    if( v < 0 ) error("combine:set_amount less than 1.\n");
	if( v==0 ) destruct(this_object());
/*
      {
          this_object()->set_weight(0);
          call_out("destruct_me", 1);
      }
*/
    else {
        amount = v;
        this_object()->set_weight(v * (int)query("base_weight"));
    }
}
void add_amount(int v) { set_amount(amount+v); }
string short()
{
    return chinese_number(query_amount()) + query("base_unit")
        + ::short();
}
varargs int move(mixed dest, int silent)
{
    object env, *inv;
    int i, total;
    string file;
    if( ::move(dest, silent) ) {
//      if( living(env = environment()) ) {
        env = environment();
            file = base_name(this_object());
            inv = all_inventory(env);
            total = (int)query_amount();
            for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==this_object() ) continue;
                if( base_name(inv[i])==file ) {
                    total += (int)inv[i]->query_amount();
                    destruct(inv[i]);
                }
            }
              amount = total;
              weight = total * query("base_weight");
//      }
        return 1;
    }
}

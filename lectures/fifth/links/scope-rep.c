#include <stddef.h>
#include <assert.h>

/* forward declaration of 'Scope' and 'Variable' abstract types */
struct _scope_;
typedef struct _scope_ Scope;

struct _variable_;
typedef struct _variable_ Variable;


#define MAX_IDEN_LEN 16

/* a few supported data types in our hypothetical problem domain */
typedef enum { UNDEFINED = -1, 
	           CHAR, INT, FLOAT, CHAR_ARR, INT_ARR, 
	           FUNCTION
	         } DataType;

/* variables in a scope are put on a list */
struct _variable_ {
    char name[MAX_IDEN_LEN];
    DataType type;
    Variable *next;
};

/* 
 * scope contains a bunch of variable definitions.
 * of course, scopes form a linear hierarchy.
 *
 */
struct _scope_ {
    Variable *vars;
    Scope *parent;
};

/*
 * starts looking up for a variable with matching 'name'
 * if not found in the current scope, walks its parent scope, and so on.
 * global scope is the 'TOP' or "GOD" scope beyond which nothing exists!
 *
 */
DataType scope_lookup_name(Scope *scope, char name[])
{

    do {
        Variable *var = scope->vars;
        while (var != NULL) {
            if (strcmp(var->name, name) == 0) return var->type;
            var = var->next;
        }
        scope = scope->parent;
    } while (scope);

    return UNDEFINED;
}

int main()
{
	Scope inner, body, global;
    
    global.parent = NULL;
    body.parent   = &global;
    inner.parent  = &body;

    Variable in_d = { "d", INT,      NULL  }, 
             in_c = { "c", CHAR,     &in_d }, 
             in_b = { "e", FLOAT,    &in_c },
             in_a = { "a", CHAR_ARR, &in_b };
    
    inner.vars = &in_a;

    Variable bd_x = {"x", INT,       NULL  },
             bd_y = {"y", INT_ARR,   &bd_x },
             bd_a = {"a", INT,       &bd_y },
             bd_d = {"d", FLOAT,     &bd_a };

    body.vars = &bd_d;

    Variable g_y  = {"y", FLOAT,     NULL  },
             g_d  = {"d", INT_ARR,   &g_y  },
             g_p  = {"p", CHAR_ARR,  &g_d  },
             g_f  = {"f", FUNCTION,  &g_p  },
             g_g  = {"g", FUNCTION,  &g_f  };

    global.vars = &g_g;

    assert(scope_lookup_name(&global, "f") == FUNCTION);
    assert(scope_lookup_name(&global, "g") == FUNCTION);
    assert(scope_lookup_name(&global, "x") == UNDEFINED);

    assert(scope_lookup_name(&body, "x") == INT);
    assert(scope_lookup_name(&body, "f") == FUNCTION);
    assert(scope_lookup_name(&body, "y") == INT_ARR);

    assert(scope_lookup_name(&inner, "d") == INT);
    assert(scope_lookup_name(&inner, "a") == CHAR_ARR);
    assert(scope_lookup_name(&inner, "y") == INT_ARR);
    assert(scope_lookup_name(&inner, "g") == FUNCTION);

    assert(scope_lookup_name(&inner,  "foo") == UNDEFINED);
    assert(scope_lookup_name(&body,   "b")   == UNDEFINED);
    assert(scope_lookup_name(&global, "a")   == UNDEFINED);

    return 0;
}
# Item 14: Think carefully about copying behavior in resource-managing classes
Most of the time, you’ll want to choose one of the following
possibilities:

**Prohibit copying**: In many cases, it makes no sense to allow RAII
objects to be copied. This is likely to be true for a class like Lock,
because it rarely makes sense to have “copies” of synchronization
primitives.

**Reference-count the underlying resource:** Sometimes it’s desirable
to hold on to a resource until the last object using it has been
destroyed. When that’s the case, copying an RAII object should increment
the count of the number of objects referring to the resource

**Copy the underlying resource:** Sometimes you can have as many
copies of a resource as you like, and the only reason you need a
resource-managing class is to make sure that each copy is released
when you’re done with it. In that case, copying the resource-
managing object should also copy the resource it wraps.
That is, copying a resource-managing object performs a “deep
copy.”

**Transfer ownership of the underlying resource:** On rare occasion,
you may wish to make sure that only one RAII object refers to a raw resource and that when the RAII object is copied, ownership
of the resource is transferred from the copied object to the
copying object.

## Things to Remember
*  *Copying an RAII object entails copying the resource it manages, so
the copying behavior of the resource determines the copying behavior
of the RAII object.*
* *Common RAII class copying behaviors are disallowing copying and
performing reference counting, but other behaviors are possible*
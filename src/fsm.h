/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
http://www.etlcpp.com

Copyright(c) 2017 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef __ETL_FSM__
#define __ETL_FSM__

#include <stdint.h>

#include "array.h"
#include "nullptr.h"
#include "error_handler.h"
#include "exception.h"
#include "user_type.h"
#include "message_router.h"
#include "integral_limits.h"
#include "largest.h"

#undef ETL_FILE
#define ETL_FILE "34"

#ifdef ETL_COMPILER_MICROSOFT
#undef max
#endif

namespace etl
{
  /// Allow alternative type for state id.
#if !defined(ETL_FSM_STATE_ID_TYPE)
    typedef uint_least8_t fsm_state_id_t;
#else
    typedef ETL_FSM_STATE_ID_TYPE fsm_state_id_t;
#endif

  // For internal FSM use.
  typedef typename etl::larger_type<etl::message_id_t>::type fsm_internal_id_t;

  //***************************************************************************
  /// Base exception class for FSM.
  //***************************************************************************
  class fsm_exception : public etl::exception
  {
  public:

    fsm_exception(string_type what, string_type file_name, numeric_type line_number)
      : etl::exception(what, file_name, line_number)
    {
    }
  };

  //***************************************************************************
  /// Exception for null state pointer.
  //***************************************************************************
  class fsm_null_state_exception : public etl::fsm_exception
  {
  public:

    fsm_null_state_exception(string_type file_name, numeric_type line_number)
      : etl::fsm_exception(ETL_ERROR_TEXT("fsm:null state", ETL_FILE"A"), file_name, line_number)
    {
    }
  };

  //***************************************************************************
  /// Exception for invalid state id.
  //***************************************************************************
  class fsm_state_id_exception : public etl::fsm_exception
  {
  public:

    fsm_state_id_exception(string_type file_name, numeric_type line_number)
      : etl::fsm_exception(ETL_ERROR_TEXT("fsm:state id", ETL_FILE"B"), file_name, line_number)
    {
    }
  };

  //***************************************************************************
  /// Exception for incompatible state list.
  //***************************************************************************
  class fsm_state_list_exception : public etl::fsm_exception
  {
  public:

    fsm_state_list_exception(string_type file_name, numeric_type line_number)
      : etl::fsm_exception(ETL_ERROR_TEXT("fsm:state list", ETL_FILE"C"), file_name, line_number)
    {
    }
  };

  //***************************************************************************
  /// Interface class for FSM states.
  //***************************************************************************
  class ifsm_state
  {
  public:

    /// Allows ifsm_state functions to be private.
    friend class fsm_helper;

    //*******************************************
    /// Gets the id for this state.
    //*******************************************
    etl::fsm_state_id_t get_state_id() const
    {
      return state_id;
    }

  protected:

    //*******************************************
    /// Constructor.
    //*******************************************
    ifsm_state(etl::fsm_state_id_t state_id_)
      : state_id(state_id_)
    {
    }

  private:

    virtual fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message) = 0;

    virtual fsm_state_id_t on_enter_state() { return state_id; } // By default, do nothing.
    virtual void on_exit_state() {}  // By default, do nothing.

    // The state id.
    const etl::fsm_state_id_t state_id;

    // Disabled.
    ifsm_state(const ifsm_state&);
    ifsm_state& operator =(const ifsm_state&);
  };

  //***************************************************************************
  /// Helper class for FSM.
  /// Allows ifsm_state functions to be private.
  //***************************************************************************
  class fsm_helper
  {
  public:

    //*******************************************
    inline fsm_state_id_t process_event(etl::ifsm_state&      state,
                                        etl::imessage_router& source,
                                        const etl::imessage&  message)
    {
      return state.process_event(source, message);
    }

    //*******************************************
    inline fsm_state_id_t on_enter_state(etl::ifsm_state& state)
    {
      return state.on_enter_state();
    }

    //*******************************************
    inline void on_exit_state(etl::ifsm_state& state)
    {
      state.on_exit_state();
    }
  };

  //***************************************************************************
  // The code below has been auto generated. Do not manually edit.
  //***************************************************************************
  template <const fsm_internal_id_t ID1 = etl::integral_limits<fsm_internal_id_t>::max - 0, 
            const fsm_internal_id_t ID2 = etl::integral_limits<fsm_internal_id_t>::max - 1, 
            const fsm_internal_id_t ID3 = etl::integral_limits<fsm_internal_id_t>::max - 2, 
            const fsm_internal_id_t ID4 = etl::integral_limits<fsm_internal_id_t>::max - 3, 
            const fsm_internal_id_t ID5 = etl::integral_limits<fsm_internal_id_t>::max - 4, 
            const fsm_internal_id_t ID6 = etl::integral_limits<fsm_internal_id_t>::max - 5, 
            const fsm_internal_id_t ID7 = etl::integral_limits<fsm_internal_id_t>::max - 6, 
            const fsm_internal_id_t ID8 = etl::integral_limits<fsm_internal_id_t>::max - 7, 
            const fsm_internal_id_t ID9 = etl::integral_limits<fsm_internal_id_t>::max - 8, 
            const fsm_internal_id_t ID10 = etl::integral_limits<fsm_internal_id_t>::max - 9, 
            const fsm_internal_id_t ID11 = etl::integral_limits<fsm_internal_id_t>::max - 10, 
            const fsm_internal_id_t ID12 = etl::integral_limits<fsm_internal_id_t>::max - 11, 
            const fsm_internal_id_t ID13 = etl::integral_limits<fsm_internal_id_t>::max - 12, 
            const fsm_internal_id_t ID14 = etl::integral_limits<fsm_internal_id_t>::max - 13, 
            const fsm_internal_id_t ID15 = etl::integral_limits<fsm_internal_id_t>::max - 14, 
            const fsm_internal_id_t ID16 = etl::integral_limits<fsm_internal_id_t>::max - 15>
  //***************************************************************************
  // The code above has been auto generated. Do not manually edit.
  //***************************************************************************
  class fsm : public etl::imessage_router , protected etl::fsm_helper
  {
  public:

    //*******************************************
    /// Constructor.
    //*******************************************
    fsm()
      : p_state(nullptr)
    {
    }

    //*******************************************
    /// Set the states for the FSM
    //*******************************************
    template <typename TSize>
    void set_states(etl::ifsm_state** p_states, TSize size)
    {
      state_list       = p_states;
      number_of_states = etl::fsm_state_id_t(size);

      ETL_ASSERT((number_of_states > 0), ETL_ERROR(etl::fsm_state_list_exception));

      for (etl::fsm_state_id_t i = 0; i < size; ++i)
      {
        ETL_ASSERT((state_list[i] != nullptr), ETL_ERROR(etl::fsm_null_state_exception));
      }
    }

    //*******************************************
    /// Starts the FSM.
    /// Can only be called once.
    /// Subsequent calls will do nothing.
    //*******************************************
    void start()
    {
      // Can only be started once.
      if (p_state == nullptr)
      {
        p_state = state_list[0];
        ETL_ASSERT(p_state != nullptr, ETL_ERROR(etl::fsm_null_state_exception));

        fsm_helper::on_enter_state(*p_state);
      }
    }

    //*******************************************
    /// Top level message handlers for the FSM.
    //*******************************************
    void receive(const etl::imessage& message)
    {
      etl::null_message_router nmr;
      receive(nmr, message);
    }

    //*******************************************
    void receive(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t next_state_id = fsm_helper::process_event(*p_state, source, message);
      ETL_ASSERT(next_state_id < number_of_states, ETL_ERROR(etl::fsm_state_id_exception));

      etl::ifsm_state* p_next_state = state_list[next_state_id];

      // Have we changed state?
      if (p_next_state != p_state)
      {
        do
        {
          p_state = p_next_state;
          fsm_helper::on_exit_state(*p_state);

          next_state_id = fsm_helper::on_enter_state(*p_state);
          ETL_ASSERT(next_state_id < number_of_states, ETL_ERROR(etl::fsm_state_id_exception));

          p_next_state = state_list[next_state_id];

        } while (p_next_state != p_state); // Have we changed state again?
      }
    }

    //*******************************************
    /// Does this FSM accept the message?
    //*******************************************
    bool accepts(const etl::imessage& msg) const
    {
      return accepts(msg.get_message_id());
    }

    //*******************************************
    /// Does this FSM accept the message id?
    //*******************************************
    bool accepts(etl::message_id_t id) const
    {
      //***************************************************************************
      // The code below has been auto generated. Do not manually edit.
      //***************************************************************************
      switch (fsm_internal_id_t(id))
      {
        case ID1: case ID2: case ID3: case ID4: case ID5: case ID6: case ID7: case ID8: 
        case ID9: case ID10: case ID11: case ID12: case ID13: case ID14: case ID15: case ID16: 
          return true; break;
        default:
          return false; break;
      }
      //***************************************************************************
      // The code above has been auto generated. Do not manually edit.
      //***************************************************************************
    }

    //*******************************************
    /// Gets the current state id.
    //*******************************************
    etl::fsm_state_id_t get_state_id() const
    {
      ETL_ASSERT(p_state != nullptr, ETL_ERROR(etl::fsm_null_state_exception));
      return p_state->get_state_id();
    }

    //*******************************************
    /// Gets a reference to the current state interface.
    //*******************************************
    ifsm_state& get_state()
    {
      ETL_ASSERT(p_state != nullptr, ETL_ERROR(etl::fsm_null_state_exception));
      return *p_state;
    }

    //*******************************************
    /// Gets a const reference to the current state interface.
    //*******************************************
    const ifsm_state& get_state() const
    {
      ETL_ASSERT(p_state != nullptr, ETL_ERROR(etl::fsm_null_state_exception));
      return *p_state;
    }

    //*******************************************
    /// Checks if the FSM has been started.
    //*******************************************
    bool is_started() const
    {
      return p_state != nullptr;
    }

    //*******************************************
    /// Reset the FSM to pre-started state.
    //*******************************************
    void reset()
    {
      p_state = nullptr;
    }

  private:

    etl::ifsm_state*    p_state;          ///< A pointer to the current state.
    etl::ifsm_state**   state_list;       ///< The list of added states.
    etl::fsm_state_id_t number_of_states; ///< The number of states.
  };

  //***************************************************************************
  // To generate to header file, run this at the command line.
  // Note: You will need Python and COG installed.
  //
  // python -m cogapp -d -e -ofsm.h -DHandlers=<n> fsm_generator.h
  // Where <n> is the number of messages to support.
  //
  // e.g.
  // To generate handlers for up to 16 events...
  // python -m cogapp -d -e -ofsm.h -DHandlers=16 fsm_generator.h
  //
  // See CreateFSM.bat
  //***************************************************************************

  //***************************************************************************
  // The code below has been auto generated. Do not manually edit.
  //***************************************************************************

  //***************************************************************************
  // The definition for all 16 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1 = void, typename T2 = void, typename T3 = void, typename T4 = void, 
            typename T5 = void, typename T6 = void, typename T7 = void, typename T8 = void, 
            typename T9 = void, typename T10 = void, typename T11 = void, typename T12 = void, 
            typename T13 = void, typename T14 = void, typename T15 = void, typename T16 = void>
  class fsm_state : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        case T6::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T6&>(message)); break;
        case T7::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T7&>(message)); break;
        case T8::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T8&>(message)); break;
        case T9::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T9&>(message)); break;
        case T10::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T10&>(message)); break;
        case T11::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T11&>(message)); break;
        case T12::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T12&>(message)); break;
        case T13::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T13&>(message)); break;
        case T14::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T14&>(message)); break;
        case T15::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T15&>(message)); break;
        case T16::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T16&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 15 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4, 
            typename T5, typename T6, typename T7, typename T8, 
            typename T9, typename T10, typename T11, typename T12, 
            typename T13, typename T14, typename T15>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        case T6::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T6&>(message)); break;
        case T7::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T7&>(message)); break;
        case T8::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T8&>(message)); break;
        case T9::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T9&>(message)); break;
        case T10::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T10&>(message)); break;
        case T11::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T11&>(message)); break;
        case T12::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T12&>(message)); break;
        case T13::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T13&>(message)); break;
        case T14::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T14&>(message)); break;
        case T15::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T15&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 14 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4, 
            typename T5, typename T6, typename T7, typename T8, 
            typename T9, typename T10, typename T11, typename T12, 
            typename T13, typename T14>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        case T6::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T6&>(message)); break;
        case T7::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T7&>(message)); break;
        case T8::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T8&>(message)); break;
        case T9::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T9&>(message)); break;
        case T10::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T10&>(message)); break;
        case T11::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T11&>(message)); break;
        case T12::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T12&>(message)); break;
        case T13::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T13&>(message)); break;
        case T14::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T14&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 13 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4, 
            typename T5, typename T6, typename T7, typename T8, 
            typename T9, typename T10, typename T11, typename T12, 
            typename T13>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        case T6::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T6&>(message)); break;
        case T7::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T7&>(message)); break;
        case T8::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T8&>(message)); break;
        case T9::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T9&>(message)); break;
        case T10::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T10&>(message)); break;
        case T11::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T11&>(message)); break;
        case T12::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T12&>(message)); break;
        case T13::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T13&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 12 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4, 
            typename T5, typename T6, typename T7, typename T8, 
            typename T9, typename T10, typename T11, typename T12>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        case T6::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T6&>(message)); break;
        case T7::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T7&>(message)); break;
        case T8::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T8&>(message)); break;
        case T9::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T9&>(message)); break;
        case T10::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T10&>(message)); break;
        case T11::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T11&>(message)); break;
        case T12::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T12&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 11 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4, 
            typename T5, typename T6, typename T7, typename T8, 
            typename T9, typename T10, typename T11>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        case T6::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T6&>(message)); break;
        case T7::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T7&>(message)); break;
        case T8::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T8&>(message)); break;
        case T9::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T9&>(message)); break;
        case T10::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T10&>(message)); break;
        case T11::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T11&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 10 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4, 
            typename T5, typename T6, typename T7, typename T8, 
            typename T9, typename T10>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, void, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        case T6::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T6&>(message)); break;
        case T7::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T7&>(message)); break;
        case T8::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T8&>(message)); break;
        case T9::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T9&>(message)); break;
        case T10::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T10&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 9 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4, 
            typename T5, typename T6, typename T7, typename T8, 
            typename T9>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, T5, T6, T7, T8, T9, void, void, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        case T6::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T6&>(message)); break;
        case T7::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T7&>(message)); break;
        case T8::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T8&>(message)); break;
        case T9::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T9&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 8 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4, 
            typename T5, typename T6, typename T7, typename T8>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, T5, T6, T7, T8, void, void, void, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        case T6::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T6&>(message)); break;
        case T7::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T7&>(message)); break;
        case T8::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T8&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 7 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4, 
            typename T5, typename T6, typename T7>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, T5, T6, T7, void, void, void, void, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        case T6::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T6&>(message)); break;
        case T7::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T7&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 6 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4, 
            typename T5, typename T6>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, T5, T6, void, void, void, void, void, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        case T6::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T6&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 5 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4, 
            typename T5>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, T5, void, void, void, void, void, void, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        case T5::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T5&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 4 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3, typename T4>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, T4, void, void, void, void, void, void, void, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        case T4::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T4&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 3 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2, typename T3>
  class fsm_state<TState, STATE_ID_, T1, T2, T3, void, void, void, void, void, void, void, void, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        case T3::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T3&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 2 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1, typename T2>
  class fsm_state<TState, STATE_ID_, T1, T2, void, void, void, void, void, void, void, void, void, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        case T2::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T2&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 1 message type.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_, 
            typename T1>
  class fsm_state<TState, STATE_ID_, T1, void, void, void, void, void, void, void, void, void, void, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      etl::fsm_state_id_t new_state_id;
      etl::message_id_t event_id = message.get_message_id();

      switch (event_id)
      {
        case T1::ID: new_state_id = static_cast<TState*>(this)->on_event(source, static_cast<const T1&>(message)); break;
        default: new_state_id = static_cast<TState*>(this)->on_event_unknown(source, message); break;
      }

      return new_state_id;
    }
  };

  //***************************************************************************
  // Specialisation for 0 message types.
  //***************************************************************************
  template <typename TState, const etl::fsm_state_id_t STATE_ID_>
  class fsm_state<TState, STATE_ID_, void, void, void, void, void, void, void, void, void, void, void, void, void, void, void, void> : public ifsm_state
  {
  public:

    enum
    {
      STATE_ID = STATE_ID_
    };

    fsm_state()
      : ifsm_state(STATE_ID)
    {
    }

  private:

    etl::fsm_state_id_t process_event(etl::imessage_router& source, const etl::imessage& message)
    {
      return static_cast<TState*>(this)->on_event_unknown(source, message);
    }
  };
}

#undef ETL_FILE

#ifdef ETL_COMPILER_MICROSOFT
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#endif
